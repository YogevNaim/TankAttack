#pragma once

#include "Pawn.h"

class Tank : public Pawn
{
public:
	Tank(Game& game, Vec2 location, Vec2 velocity, Vec2 size, ObjectType type, COLOUR color = COLOUR::FG_WHITE, bool isAlive = true);
	~Tank() {};

	void Draw() override;

protected:
	virtual void UpdateMovement(float fElapsedTime) override;

private:
	Vec2 m_FwdVector = Vec2{1.f, 0.f};
};

