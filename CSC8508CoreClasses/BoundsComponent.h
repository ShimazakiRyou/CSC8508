#pragma once
//
// Contributors: Alasdair
//

#ifndef BOUNDSCOMPONENT_H
#define BOUNDSCOMPONENT_H

#include "Transform.h"
#include "IComponent.h"
#include "CollisionVolume.h"

using std::vector;

namespace NCL::CSC8508
{

	namespace PhysicsLayers {
		enum LayerID { Default, Ignore_RayCast, UI, Player, Enemy, Ignore_Collisions };
	}

	class GameObject;
	class PhysicsObject;

	class BoundsComponent : public IComponent
	{
	public:

		BoundsComponent(GameObject* gameObject, CollisionVolume* collisionVolume);

		~BoundsComponent();

		/**
		 * Function invoked each frame.
		 * @param deltaTime Time since last frame
		 */
		void Update(float deltaTime) override;

		/**
		 * Function invoked each frame after Update.
		 * @param deltaTime Time since last frame
		 */
		void LateUpdate(float deltaTime) override;

		/**
		 * Function invoked when the component is enabled.
		 */
		void OnEnable() override;

		/**
		 * Function invoked when the component is disabled.
		 */
		void OnDisable() override;

		void SetBoundingVolume(CollisionVolume* vol) {
			boundingVolume = vol;
		}

		const CollisionVolume* GetBoundingVolume() const {
			return boundingVolume;
		}

		bool GetBroadphaseAABB(Vector3& outsize) const;

		void UpdateBroadphaseAABB();

		void AddToIgnoredLayers(PhysicsLayers::LayerID layerID) { ignoreLayers.push_back(layerID); }
		const std::vector<PhysicsLayers::LayerID>& GetIgnoredLayers() const { return ignoreLayers; }

	protected:
		CollisionVolume* boundingVolume;
		Vector3 broadphaseAABB;
		vector<PhysicsLayers::LayerID> ignoreLayers;
	};
}

#endif //BOUNDSCOMPONENT_H
