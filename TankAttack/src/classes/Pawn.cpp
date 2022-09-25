#include "Pawn.h"

Pawn::Pawn(Game& game, Vec2 location, Vec2 velocity, Vec2 size, ObjectType type, Vec2 fwdVec, COLOUR color , bool isAlive)
	: Object(game, location, velocity, size, type, color, isAlive), m_FwdVector(fwdVec) {}

Pawn::~Pawn()
{
}

bool Pawn::OnUserUpdate(float fElapsedTime)
{
	
	// Handle pawn movement
	UpdateMovement(fElapsedTime);

	return true;
}

void Pawn::UpdateMovement(float fElapsedTime)
{
	if (m_Velocity.m_X != 0.f || m_Velocity.m_Y != 0.f)
	{
		m_FwdVector = m_Velocity;

		Vec2 newLocation = m_Location + m_Velocity * fElapsedTime * m_SpeedMultiplier;
		
		// Check new location is valid
		for (auto object : m_Game->GetObjects())
		{
			// Pawn to pawn collision
			if (object->GetType() == ObjectType::PLAYER) continue;
			
			// Pawn to object collision
			if (Object::SquareObjectCollision(*this, *object, newLocation)) return;
		}
		SetLocation(newLocation);
	}
}
