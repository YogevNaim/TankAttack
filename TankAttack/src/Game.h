#pragma once

#include "olcConsoleGameEngine.h"
#include "utils/Math.h"

class Object;
class Pawn;

class Game : public olcConsoleGameEngineOOP
{
public:
	Game();
	~Game();

	// olcConsoleGameEngine

protected:
	virtual bool OnUserCreate() override;
	virtual bool OnUserUpdate(float fElapsedTime) override;
	void HandlePlayerMoveInputs();
	void ResetGame();


private:
	const short m_WindowWidth = 120;
	const short m_WindowHeight = 120;
	const short m_FontSize = 8;

	std::weak_ptr<Pawn> m_Player;
	std::vector<std::shared_ptr<Object>> m_Object;
};
