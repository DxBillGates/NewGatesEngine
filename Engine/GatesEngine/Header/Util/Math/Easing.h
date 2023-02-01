#pragma once
namespace GE
{
	namespace Math
	{
		//イージングチートシート
		namespace Easing
		{
			float Lerp(float s, float e, float t);
			float EaseInSine(float t);
			float EaseOutSine(float t);
			float EaseInOutSine(float t);
			float EaseInQuad(float t);
			float EaseOutQuad(float t);
			float EaseInOutQuad(float x);
			float EaseInCubic(float x);
			float EaseOutCubic(float x);
			float EaseInOutCubic(float x);
			float EaseInQuart(float x);
			float EaseOutQuart(float x);
			float EaseInOutQuart(float x);
			float EaseInQuint(float x);
			float EaseOutQuint(float x);
			float EaseInOutQuint(float x);
			float EaseInExpo(float x);
			float EaseOutExpo(float x);
			float EaseInOutExpo(float x);
			float EaseInCirc(float x);
			float EaseOutCirc(float x);
			float EaseInOutCirc(float x);
			float EaseInBack(float x);
			float EaseOutBack(float x);
			float EaseInOutBack(float x);
			float EaseInElastic(float x);
			float EaseOutElastic(float x);
			float EaseInOutElastic(float x);
			float EaseInBounce(float x);
			float EaseOutBounce(float x);
			float EaseInOutBounce(float x);
		};
	}
}