#pragma once

#include <fmod.hpp>
#include "AudioEngine.h"
#include "Maths.h"
#include "Debug.h"
#include <Transform.h>


using namespace NCL;
using namespace NCL::Maths;
using namespace NCL::CSC8508;


/**
* Base class for all audio objects (listeners, sound sources)
* will eventually inherit from component class for component system
* 
*/
class AudioObject
{

public:
	

	/**
	* Update vectors of object for use by FMOD
	* override in derived classes
	*/
	virtual void Update() {
		Vector3 pos = transform->GetPosition();
		fPosition = VecToFMOD(pos);

		//todo: get velocity from physics component
		//Vector3 vel = transform->GetVelocity();
		//fVelocity = VecToFMOD(vel);
	}

protected:
	AudioObject(Transform* transform) {

		fSystem = AudioEngine::Instance().GetSystem();

		this->transform = transform;

		Vector3 zero = Vector3(0, 0, 0);
		fVelocity = VecToFMOD(zero);

	};

	Transform* transform;

	FMOD::System* fSystem;

	FMOD_VECTOR fPosition;
	FMOD_VECTOR fVelocity;

	static FMOD_VECTOR VecToFMOD(const Vector3& vec) {
		FMOD_VECTOR fVec;
		fVec.x = vec.x;
		fVec.y = vec.y;
		fVec.z = vec.z;
		return fVec;
	}


};






