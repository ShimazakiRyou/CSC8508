//
// Contributors: Alasdair
//

#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include "Transform.h"
#include "IComponent.h"
#include "CollisionVolume.h"

using std::vector;

namespace NCL::CSC8508
{

	class GameObject;
	class PhysicsObject;
	 
	class PhysicsComponent : public IComponent
	{
	public:

		PhysicsComponent(GameObject* gameObject, CollisionVolume* collisionVolume);

		~PhysicsComponent();

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

		PhysicsObject* GetPhysicsObject() const {
			return physicsObject;
		}

		void SetPhysicsObject(PhysicsObject* newObject) {
			physicsObject = newObject;
		}

		float GetRestitution() { return restitution; }
		void SetRestitution(float newRestitution) { restitution = newRestitution; }


	protected:
		PhysicsObject* physicsObject;
		float restitution = 0.2f;
	};
}

#endif //PHYSICSCOMPONENT_H
