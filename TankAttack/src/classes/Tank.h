#pragma once

#include "Pawn.h"

class Tank : public Pawn
{
public:
	Tank(Game& game, Vec2 location, Vec2 velocity, Vec2 size, ObjectType type, Vec2 fwdVec = Vec2{ 1.f, 0.f }, COLOUR color = COLOUR::FG_WHITE, bool isAlive = true);
	~Tank() {};

	void Draw() override;
};

