//
// Contributors: Alasdair
//

#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include "Transform.h"

namespace NCL::CSC8508 
{

	class GameObject;

	class IComponent
	{
	public:

		IComponent(GameObject* gameObject) : gameObject(gameObject), enabled(true) {}

		virtual ~IComponent() = default;

		/**
		 * Function invoked each frame.
		 * @param deltaTime Time since last frame
		 */
		virtual void Update(float deltaTime) = 0;

		/**
		 * Function invoked each frame after Update.
		 * @param deltaTime Time since last frame
		 */
		virtual void LateUpdate(float deltaTime) = 0;

		/**
		 * Function invoked when the component is enabled.
		 */
		virtual void OnEnable() = 0;

		/**
		 * Function invoked when the component is disabled.
		 */
		virtual void OnDisable() = 0;

		/**
		* Function gets the GameObject this component is attatched to.
		* @return the GameObject this component is attatched to.
		*/
		GameObject* GetGameObject();

		/**
		* Function Gets the enabled state of the component.
		* @return the enabled state
		*/
		bool IsEnabled() const;

		/**
		* Function sets the enabled state of the component.
		* @param the new enabled state
		*/
		void SetEnabled(bool enabled);

		/**
		* Function gets the component type
		* @return the component type
		*/
		virtual const char* GetType() const {
			return typeid(*this).name();
		}

	private:
		GameObject* gameObject;
		bool enabled;
	};
}

#endif //ICOMPONENT_H
