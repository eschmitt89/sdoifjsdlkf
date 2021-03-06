#include "PhysicsObject.hpp"

PhysicsObject::PhysicsObject(const sf::Texture* texture, sf::Vector2f position, sf::Vector2f size)
	: Object(texture, position, size)
{
	gravity = 1200;
	velocity = sf::Vector2f(10, 20);
	acceleration = sf::Vector2f(0, gravity);
	friction = sf::Vector2f(0.5, 0.5);
	elasticity = 0.5;
	mass = 1;

	xState = XState_NotOnWall;
	yState = YState_InAir;

	collidesWithPhysicsObjects = true;
	expired = false;
}

////////////////////////////////////////////////////////////////////////

PhysicsObject::~PhysicsObject()
{
    
}

////////////////////////////////////////////////////////////////////////

void PhysicsObject::Update(float dt)
{
	SetPosition(position);
}

////////////////////////////////////////////////////////////////////////

void PhysicsObject::UpdateX(float dt)
{
	xState = XState_NotOnWall;

	velocity.x += acceleration.x * dt;
	position.x += velocity.x * dt;
}

////////////////////////////////////////////////////////////////////////

void PhysicsObject::UpdateY(float dt)
{
	yState = YState_InAir;

	velocity.y += acceleration.y * dt;
	position.y += velocity.y * dt;
}

////////////////////////////////////////////////////////////////////////

void PhysicsObject::Impulse(sf::Vector2f vector)
{
	velocity += vector;
}

////////////////////////////////////////////////////////////////////////

sf::Vector2f PhysicsObject::GetVelocity()
{
	return velocity;
}

////////////////////////////////////////////////////////////////////////

float PhysicsObject::GetElasticity()
{
	return elasticity;
}

////////////////////////////////////////////////////////////////////////

float PhysicsObject::GetMass()
{
	return mass;
}

////////////////////////////////////////////////////////////////////////

bool PhysicsObject::GetCollidesWithPhysicsObjects()
{
	return collidesWithPhysicsObjects;
}

////////////////////////////////////////////////////////////////////////

bool PhysicsObject::GetExpired()
{
	return expired;
}

////////////////////////////////////////////////////////////////////////

void PhysicsObject::SetExpired(bool expired)
{
	this->expired = expired;
}

////////////////////////////////////////////////////////////////////////

void PhysicsObject::ResolveBlockCollisionX(vector<vector<Block>> blocks, float dt)
{
	
}

////////////////////////////////////////////////////////////////////////

void PhysicsObject::ResolveBlockCollisionY(vector<vector<Block>> blocks, float dt)
{

}

////////////////////////////////////////////////////////////////////////

void PhysicsObject::ResolveBlockCollisionX(Block block, float dt)
{
	if (velocity.x < 0)
	{
		xState = XState_OnWallLeft;
		position.x = block.GetPosition().x + block.GetSize().x;
	}
	else
	{
		xState = XState_OnWallRight;
		position.x = block.GetPosition().x - size.x;
	}

	velocity.x *= -elasticity;
	velocity.y *= pow(1 - friction.y, dt);
}

////////////////////////////////////////////////////////////////////////

void PhysicsObject::ResolveBlockCollisionY(Block block, float dt)
{
	if (velocity.y < 0)
	{
		yState = YState_OnCeiling;
		position.y = block.GetPosition().y + block.GetSize().y;
	}
	else
	{
		yState = YState_OnGround;
		position.y = block.GetPosition().y - size.y;
	}

	velocity.x *= pow(1 - friction.x, dt);
	velocity.y *= -elasticity;
}

////////////////////////////////////////////////////////////////////////

void PhysicsObject::CollideWith(PhysicsObject * physicsObject)
{

}

////////////////////////////////////////////////////////////////////////

void PhysicsObject::ResolveBlockCollisionXFunction(PhysicsObject* physicsObject, Block block, float dt)
{
	physicsObject->ResolveBlockCollisionX(block, dt);
}

////////////////////////////////////////////////////////////////////////

void PhysicsObject::ResolveBlockCollisionYFunction(PhysicsObject* physicsObject, Block block, float dt)
{
	physicsObject->ResolveBlockCollisionY(block, dt);
}

////////////////////////////////////////////////////////////////////////

void PhysicsObject::SpawnPhysicsObjects(vector<PhysicsObject*>& physicsManagerObjects)
{
	physicsManagerObjects.insert(physicsManagerObjects.end(), spawnedPhysicsObjects.begin(), spawnedPhysicsObjects.end());

	spawnedPhysicsObjects.clear();
}

////////////////////////////////////////////////////////////////////////

void PhysicsObject::Spawn(PhysicsObject * physicsObject)
{
	spawnedPhysicsObjects.push_back(physicsObject);
}

////////////////////////////////////////////////////////////////////////

