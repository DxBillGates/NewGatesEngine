#pragma once
#include <string>
#include <vector>

namespace GE
{
	namespace IO
	{
		// directoryを指定してそのdirectory内でのファイルロード関係を行えるクラス
		class DirectoryFileLoader
		{
		private:
			std::string directoryPath;
		public:
			/// <param name="directoryPath">相対パスでフォルダ名(例:resources,texture)、スラッシュはつけない</param>
			DirectoryFileLoader(const std::string& directoryPath);

			/// <summary>
			/// ディレクトリの再設定
			/// </summary>
			/// <param name="setDirectorypath">設定したいディレクトリパス</param>
			void SetDirectory(const std::string& setDirectorypath);

			/// <summary>
			/// directory内の指定した拡張子のファイルパスを一覧取得する関数
			/// </summary>
			/// <param name="extension">拡張子指定　指定名+拡張子も可能 ドットはつける</param>
			/// <param name="filenames">一覧取得を格納するための配列</param>
			void GetFilepaths(const std::string& extension,std::vector<std::string>& filenames);
		};
	}
}
