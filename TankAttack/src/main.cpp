#include <iostream>
#include <memory>

#include "Game.h"

int main(int argc, char** argv)
{
	std::unique_ptr<Game> game = std::make_unique<Game>();

	return 0;
}
