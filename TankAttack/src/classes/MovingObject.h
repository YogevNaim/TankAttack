#pragma once

#include "Object.h"

class MovingObject : public Object
{
public:
	MovingObject(Game& game, Vec2 location, Vec2 velocity, Vec2 size, ObjectType type, Vec2 fwdVec, COLOUR color = COLOUR::FG_WHITE, bool isAlive = true);
	~MovingObject();

	virtual bool OnUserUpdate(float fElapsedTime)  override;

	Vec2 GetFwdVector() const { return m_FwdVector; }

protected:
	virtual void UpdateMovement(float fElapsedTime);

	Vec2 m_FwdVector;
};
