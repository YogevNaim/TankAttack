#pragma once

#include "Object.h"

class Pawn : public Object
{
public:
	Pawn(Game& game, Vec2 location, Vec2 velocity, Vec2 size, ObjectType type, COLOUR color = COLOUR::FG_WHITE, bool isAlive = true);
	~Pawn();

	virtual bool OnUserUpdate(float fElapsedTime)  override;

protected:
	virtual void UpdateMovement(float fElapsedTime);

};
