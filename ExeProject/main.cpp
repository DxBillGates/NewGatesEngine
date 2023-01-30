#include <GatesEngine/Header/Util/Utility.h>
#include <GatesEngine/Header/Util/Random.h>
#include <GatesEngine/Header/Util/Timer.h>

int main()
{
	GE::Utility::Timer timer;
	GE::Utility::RandomMaker::Reset();
	timer.Start();
	auto test = GE::Utility::RandomMaker::GetFloat(-100,100);
	timer.End();
	return 0;
}