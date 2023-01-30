#include "..\..\Header\Util\Timer.h"
#include "..\..\Header\Util\Utility.h"

GE::Utility::Timer::Timer()
	: timeStart({})
	, timeEnd({})
	, timeFreq({})
{
	QueryPerformanceFrequency(&timeFreq);
}

GE::Utility::Timer::~Timer()
{
}

void GE::Utility::Timer::Start()
{
	QueryPerformanceCounter(&timeStart);
}

float GE::Utility::Timer::End(bool isShow, const char* addComment)
{
	QueryPerformanceCounter(&timeEnd);
	double elapsedTime = static_cast<double>(timeEnd.QuadPart - timeStart.QuadPart) / static_cast<double>(timeFreq.QuadPart);
	float fps = 1.0f / (float)elapsedTime;
	if (isShow)Utility::Printf("%3.5fms : %3.0ffps : %s\n", (float)(elapsedTime * 1000), fps, addComment);
	return (float)elapsedTime;
}
