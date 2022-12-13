
#pragma once
#include "Behaviour.h"

namespace GE
{
	class SampleBehaviour : public Behaviour
	{
	public:
		SampleBehaviour();
		~SampleBehaviour();

		void Awake()override;
		void Start()override;
		void Update(float deltaTime)override;

		void OnDestroy()override;
		void OnGUI()override;

		void OnCollisionEnter(GameObject* other)override;
		void OnCollisionStay(GameObject* other)override;
		void OnCollisionExit(GameObject* other)override;
	};
}
