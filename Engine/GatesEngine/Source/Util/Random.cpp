#include "..\..\Header\Util\Random.h"

std::mt19937_64 GE::Utility::RandomMaker::rnd = std::mt19937_64();

void GE::Utility::RandomMaker::Reset()
{
	std::random_device rndDevice;
	rnd = std::mt19937_64(rndDevice());
}

int GE::Utility::RandomMaker::GetInt(int minValue, int maxValue)
{
	std::uniform_int_distribution<int> range(minValue, maxValue);
	return range(rnd);
}

float GE::Utility::RandomMaker::GetFloat(float minValue, float maxValue)
{
	std::uniform_real_distribution<float> range(minValue, maxValue);
	return range(rnd);
}
