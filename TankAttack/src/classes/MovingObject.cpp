#include "MovingObject.h"

MovingObject::MovingObject(Game& game, Vec2 location, Vec2 velocity, Vec2 size, ObjectType type, Vec2 fwdVec, COLOUR color , bool isAlive)
	: Object(game, location, velocity, size, type, color, isAlive), m_FwdVector(fwdVec) {}

MovingObject::~MovingObject()
{
}

bool MovingObject::OnUserUpdate(float fElapsedTime)
{
	
	// Handle pawn movement
	UpdateMovement(fElapsedTime);

	return true;
}

void MovingObject::UpdateMovement(float fElapsedTime)
{
	Vec2 velocity = GetVelocity();
	if (velocity.m_X != 0.f || velocity.m_Y != 0.f)
	{
		m_FwdVector = velocity;

		Vec2 newLocation = GetLocation() + velocity * fElapsedTime * GetSpeedMultiplier();
		
		// Check new location is valid
		for (auto object : GetGameRef()->GetObjects())
		{
			// MovingObject to pawn collision
			if (object->GetType() == ObjectType::PLAYER) continue;
			
			// MovingObject to object collision
			if (Object::SquareObjectCollision(*this, *object, newLocation)) return;
		}
		SetLocation(newLocation);
	}
}
