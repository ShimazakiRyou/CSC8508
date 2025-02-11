//
// Contributors: Alasdair
//

#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include "Transform.h"
#include "GameObject.h"

namespace NCL::CSC8508 
{
	class IComponent
	{
	public:

		IComponent(GameObject& gameObject) : gameObject(gameObject), enabled(true) {}

		virtual ~IComponent() = default;


		/**
		 * Function invoked after the object and components have been instantiated.
		 * @param deltaTime Time since last frame
		 */
		void InvokeOnAwake() { OnAwake(); }

		/**
		 * Function invoked each frame.
		 * @param deltaTime Time since last frame
		 */
		void InvokeUpdate(float deltaTime) { Update(deltaTime); }

		/**
		 * Function invoked each frame after Update.
		 * @param deltaTime Time since last frame
		 */
		void InvokeLateUpdate(float deltaTime) { LateUpdate(deltaTime); }

		/**
		 * Function invoked when the component is enabled.
		 */
		void InvokeOnEnable() { OnEnable(); }

		/**
		 * Function invoked when the component is disabled.
		 */
		void InvokeOnDisable() { OnDisable(); }

		/**
		* Function gets the GameObject this component is attatched to.
		* @return the GameObject this component is attatched to.
		*/
		GameObject& GetGameObject();

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

	protected:
		virtual void OnAwake() {}
		virtual void Update(float deltaTime) {}
		virtual void LateUpdate(float deltaTime) {}
		virtual void OnEnable() {}
		virtual void OnDisable() {}

	private:
		GameObject& gameObject;
		bool enabled;
	};
}

#endif //ICOMPONENT_H
