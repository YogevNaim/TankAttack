#pragma once

#include "MovingObject.h"

class Tank : public MovingObject
{
public:
	Tank(Game& game, Vec2 location, Vec2 velocity, Vec2 size, ObjectType type, Vec2 fwdVec = Vec2{ 1.f, 0.f }, COLOUR color = COLOUR::FG_WHITE, bool isAlive = true);
	~Tank() {}

	void Draw() override;
	bool OnUserUpdate(float fElapsedTime) override;
	void OnCollision(Object& other, const Vec2& location) override;

	bool CanShoot() const { return m_CanShoot; }
	void Shoot();

protected:
	void UpdateCanShoot(float fElapsedTime);

private:
	bool m_CanShoot = true;
	float m_ShootInterval = 1.f;
	double m_LastShoot = 0;
};
