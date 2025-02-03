#pragma once
#include "Transform.h"
#include "CollisionVolume.h"

using std::vector;

namespace NCL::CSC8508 {

	namespace Tags {
		enum Tag { Default, Player, Enemy, Kitten, CursorCast, Ground, Collect };
	}

	namespace Layers {
		enum LayerID { Default, Ignore_RayCast, UI, Player, Enemy, Ignore_Collisions };
	}

	class NetworkObject;
	class RenderObject;
	class PhysicsObject;
	class IComponent;

	class GameObject	{
	public:
		GameObject(const std::string& name = "");
		~GameObject();


		bool IsActive() const {
			return isActive;
		}

		Transform& GetTransform() {
			return transform;
		}

		RenderObject* GetRenderObject() const {
			return renderObject;
		}

		NetworkObject* GetNetworkObject() const {
			return networkObject;
		}

		void SetRenderObject(RenderObject* newObject) {
			renderObject = newObject;
		}

		void SetNetworkObject(NetworkObject* newObject) {
			networkObject = newObject;
		}

		const std::string& GetName() const {
			return name;
		}

		virtual void OnCollisionBegin(GameObject* otherObject) {
			//std::cout << "OnCollisionBegin event occured!\n";
		}

		virtual void OnCollisionEnd(GameObject* otherObject) {
			//std::cout << "OnCollisionEnd event occured!\n";
		}

		void SetWorldID(int newID) {
			worldID = newID;
		}

		int	GetWorldID() const {
			return worldID;
		}	

		void SetLayerID(Layers::LayerID newID) { layerID = newID;}
		Layers::LayerID GetLayerID() const {return layerID; }
		void SetTag(Tags::Tag newTag) {  tag = newTag;}
		Tags::Tag GetTag() const { return tag;}



	protected:
		Transform			transform;
		RenderObject*		renderObject;
		NetworkObject*		networkObject;

		vector<IComponent> components; 

		bool isActive;
		int	worldID;

		Layers::LayerID	layerID;
		Tags::Tag	tag;
		std::string	name;
	};
}

