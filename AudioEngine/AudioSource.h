#ifndef ASSETROOTLOCATION
#define ASSETROOTLOCATION "../Assets/"
#endif

#include "AudioObject.h"
#include <string>
#include <filesystem>
#include <iostream>
#include "Maths.h"
#include "Debug.h"
#include <Transform.h>

using namespace NCL;
using namespace NCL::Maths;
using namespace NCL::CSC8508;

/**
* Audio Source class for audio engine
*/
class AudioSource : public AudioObject
{
public:


	/**
	* Constructor for Audio Source
	* Sets default file path for audio files
	*/
	AudioSource(Transform* transform) : AudioObject(transform) {
		soundDir = std::string(ASSETROOTLOCATION) + "Audio/";

		fChannel = nullptr;
	}

	/**
	* Load sound from file
	* Different modes include FMOD_3D, FMOD_2D, FMOD_DEFAULT, FMOD_LOOP_NORMAL
	* FMOD_3D is defualt for spacial audio
	* Creates sound using Audio File Path
	* Sets volume and 3D min max distance
	* @return sound loaded status (true if successful)
	* @param filename name of audio file
	* @param volume of sound
	* @param mode of sound
	*/
	bool LoadSound(const char* filename, float vol = 1.0f, FMOD_MODE mode = FMOD_3D) {
		std::string fullPath = soundDir + filename;

		if (fSystem->createSound(fullPath.c_str(), mode, 0, &fSound) != FMOD_OK) {
			std::cerr << "Error loading sound (" << filename << "): " << std::endl;
			return false;
		}
		
		volume = vol;
		fSound->set3DMinMaxDistance(0.5f, 500.0f);
		return true;
	}


	/**
	* Play created sound
	* Checks if sound is loaded
	* Checks if sound played successfully
	* Modifies Channel status and volume
	* @return sound played status (true if successful)
	*/
	bool PlaySound() {
		if (!fSound) {
			std::cerr << "Error: fSound is nullptr, cannot play sound!" << std::endl;
			return false;
		}

		FMOD_RESULT result = fSystem->playSound(fSound, nullptr, false, &fChannel);
		if (result != FMOD_OK) {
			std::cerr << "Error playing sound: " << result << std::endl;
			return false;
		}

		if (fChannel) {
			fChannel->setPaused(false);
			fChannel->setVolume(volume);
			return true;
		}
	}



	/**
	* Stop Playback
	*/
	void StopSound() {
		fChannel ? fChannel->stop() : 0;
	};

	/**
	* Update position vectors of source for use by FMOD  
	*/
	void Update() override {

		Vector3 pos = transform->GetPosition();
		fPosition = VecToFMOD(pos);

		fChannel->set3DAttributes(&fPosition, &fVelocity);

		fSystem->update();
	}

private:

	/**
	* Destructor for Audio Source
	*/
	~AudioSource() {
		fChannel ? fChannel->stop() : 0;
	}

	FMOD::Channel* fChannel;
	std::string soundDir;
	FMOD::Sound* fSound = nullptr;
	float volume;
};