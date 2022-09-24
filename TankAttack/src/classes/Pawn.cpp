#include "Pawn.h"

Pawn::Pawn(Game& game, Vec2 location, Vec2 velocity, Vec2 size, COLOUR color, bool isAlive)
	: Object(game, location, velocity, size, color, isAlive) {}

Pawn::~Pawn()
{
}

bool Pawn::OnUserUpdate(float fElapsedTime)
{
	
	// Handle physics
	UpdateMovement(fElapsedTime);

	return true;
}

void Pawn::UpdateMovement(float fElapsedTime)
{
	if (m_Velocity.m_X != 0.f || m_Velocity.m_Y != 0.f)
	{
		Vec2 newLocation = m_Location + m_Velocity * fElapsedTime * m_SpeedMultiplier;
		SetLocation(newLocation);
	}
}
