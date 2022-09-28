#pragma once

#include "olcConsoleGameEngine.h"
#include "utils/Math.h"

class Object;
class Tank;
class Projectile;

class Game : public olcConsoleGameEngineOOP
{
public:
	Game();
	~Game();

	std::vector<std::shared_ptr<Object>> GetObjects() const { return m_Objects; };
	void SpawnProjectile(const Tank& shooter);

protected:
	// olcConsoleGameEngine
	virtual bool OnUserCreate() override;
	virtual bool OnUserUpdate(float fElapsedTime) override;
	
	// Game
	void HandlePlayerMoveInputs();
	void HandleShootingInputs();
	void ResetGame();


private:
	const short m_WindowWidth = 120;
	const short m_WindowHeight = 120;
	const short m_FontSize = 8;

	std::weak_ptr<Tank> m_Player;
	std::vector<std::shared_ptr<Object>> m_Objects;
	std::vector<std::shared_ptr<Projectile>> m_Projectiles;
};
