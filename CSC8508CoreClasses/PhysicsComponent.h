//
// Contributors: Alasdair
//

#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include "Transform.h"
#include "IComponent.h"
#include "CollisionVolume.h"
#include "BoundsComponent.h"


using std::vector;

namespace NCL::CSC8508
{
	class PhysicsObject;
	 
	class PhysicsComponent : public IComponent
	{
	public:

		PhysicsComponent(GameObject& gameObject, BoundsComponent* boundsComponent);

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

		const BoundsComponent* GetBoundsComponent() const {
			return boundsComponent;
		}

		void SetPhysicsObject(BoundsComponent* newComponent) {
			boundsComponent = newComponent;
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
		BoundsComponent* boundsComponent;
		float restitution = 0.2f;
	};
}

#endif //PHYSICSCOMPONENT_H
