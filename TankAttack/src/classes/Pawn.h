#pragma once

#include "Object.h"

class Pawn : public Object
{
public:
	Pawn();
	Pawn(Vec2 location, Vec2 velocity, Vec2 size ,bool isAlive = true);
	~Pawn();

	virtual bool OnUserUpdate(float fElapsedTime)  override;

protected:
	virtual void UpdateMovement(float fElapsedTime);

};

