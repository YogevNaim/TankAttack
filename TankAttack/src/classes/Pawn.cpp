#include "Pawn.h"

Pawn::Pawn()
	: Object() {}

Pawn::Pawn(Vec2 location, Vec2 velocity, Vec2 size, bool isAlive)
	: Object(location, velocity, size, isAlive) {}

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
	Vec2 newLocation = m_Location + m_Velocity * fElapsedTime;
	SetLocation(newLocation);
}

