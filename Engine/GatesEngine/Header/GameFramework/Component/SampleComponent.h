#pragma once
#include "Component.h"

namespace GE
{
	namespace GameFramework
	{
		class SampleComponent : public Component
		{
		public:
			SampleComponent();
			~SampleComponent();
			void Awake()override;
			void Start()override;
			void Update(float deltaTime)override;

			void OnDestroy()override;
			void OnGUI()override;
		};
	}
}