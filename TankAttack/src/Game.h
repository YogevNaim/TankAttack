#pragma once

#include "olcConsoleGameEngine.h"

class Game : public olcConsoleGameEngineOOP
{
public:
	Game();
	~Game();

	// olcConsoleGameEngine
	virtual bool OnUserCreate() override;
	virtual bool OnUserUpdate(float fElapsedTime) override;

private:
	bool m_ShouldRun = true;
	short m_WindowWidth = 160;
	short m_WindowHeight = 100;
	short m_FontSize = 8;
};

