#include "PhysicsComponent.h"
#include "CollisionDetection.h"
#include "PhysicsObject.h"
#include "RenderObject.h"
#include "NetworkObject.h"

using namespace NCL::CSC8508;

PhysicsComponent::PhysicsComponent(GameObject* gameObject, CollisionVolume* collisionVolume) : IComponent(gameObject) {
	boundingVolume = collisionVolume;
	physicsObject = nullptr;
	vector<PhysicsLayers::LayerID> ignoreLayers = vector<PhysicsLayers::LayerID>();
}

PhysicsComponent::~PhysicsComponent() {
	delete boundingVolume;
	delete physicsObject;
}

void PhysicsComponent::Update(float deltaTime) {
	if (physicsObject) {
	}
}

void PhysicsComponent::LateUpdate(float deltaTime) {
	if (physicsObject) {
	}
}

void PhysicsComponent::OnEnable() {
}

void PhysicsComponent::OnDisable() {
}
