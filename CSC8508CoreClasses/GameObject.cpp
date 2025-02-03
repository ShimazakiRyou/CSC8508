#include "GameObject.h"
#include "CollisionDetection.h"
#include "PhysicsObject.h"
#include "RenderObject.h"
#include "NetworkObject.h"

using namespace NCL::CSC8508;

GameObject::GameObject(const std::string& objectName)	{
	name			= objectName;
	worldID			= -1;
	isActive		= true;
	layerID = Layers::LayerID::Default;
	tag = Tags::Tag::Default;
	renderObject	= nullptr;
	networkObject	= nullptr;
	vector<Layers::LayerID> ignoreLayers = vector<Layers::LayerID>();
}

GameObject::~GameObject()	{
	delete renderObject;
	delete networkObject;
}
