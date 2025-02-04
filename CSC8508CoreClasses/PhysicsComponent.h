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
	class PhysicsObject;
	 
	class PhysicsComponent : public IComponent
	{
	public:

		PhysicsComponent(GameObject& gameObject);

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

		PhysicsObject* GetPhysicsObject() const {
			return physicsObject;
		}

		void SetPhysicsObject(PhysicsObject* newObject) {
			physicsObject = newObject;
		}



	protected:
		PhysicsObject* physicsObject;
	};
}

#endif //PHYSICSCOMPONENT_H
