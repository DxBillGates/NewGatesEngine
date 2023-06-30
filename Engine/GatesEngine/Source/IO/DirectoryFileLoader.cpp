#include "..\..\Header\IO\DirectoryFileLoader.h"

#include <Windows.h>

GE::IO::DirectoryFileLoader::DirectoryFileLoader(const std::string& directoryPath)
	: directoryPath(directoryPath + "/")
{
}

void GE::IO::DirectoryFileLoader::SetDirectory(const std::string& setDirectorypath)
{
	directoryPath = setDirectorypath;
}

void GE::IO::DirectoryFileLoader::GetFilepaths(const std::string& extension, std::vector<std::string>& filenames)
{
	HANDLE hFind;
	WIN32_FIND_DATA findData;
	std::string searchPath = directoryPath + "\\*" + extension;

	// �w�肵���g���q�̈�ԍŏ��̃t�@�C�����擾
	hFind = FindFirstFile(searchPath.c_str(), &findData);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		return;
	}

	// ������filenames�Ɏ擾�����t�@�C���p�X��ǉ����Ă��������_
	auto PushbackFilepath = [&filenames](WIN32_FIND_DATA& data,const std::string& directory)
	{
		// �{����string�̃f�[�^�T�C�Y�����T�[�u�����ق�������
		std::string filename = data.cFileName;
		filename.insert(0, directory.c_str());
		filenames.emplace_back(filename);
	};

	PushbackFilepath(findData, directoryPath);

	while (FindNextFile(hFind, &findData))
	{
		PushbackFilepath(findData, directoryPath);
	}

	FindClose(hFind);
}
