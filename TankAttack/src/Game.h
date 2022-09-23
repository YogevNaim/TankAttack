#pragma once

#include "olcConsoleGameEngine.h"

#include "classes/Pawn.h"

class Game : public olcConsoleGameEngineOOP
{
public:
	Game();
	~Game();

	// olcConsoleGameEngine
	virtual bool OnUserCreate() override;
	virtual bool OnUserUpdate(float fElapsedTime) override;

protected:
	void HandlePlayerMoveInputs();
	


private:
	const short m_WindowWidth = 160;
	const short m_WindowHeight = 120;
	const short m_FontSize = 8;

	std::shared_ptr<Pawn> m_Player;
	std::vector<std::shared_ptr<Object>> m_Object;
};

