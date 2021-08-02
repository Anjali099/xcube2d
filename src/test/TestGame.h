#ifndef __TEST_GAME_H__
#define __TEST_GAME_H__

#include "../engine/AbstractGame.h"

#include "TestMazeGenerator.h"
#include <stdlib.h>

struct GameKey {
	Point2 pos;
	bool alive;
};

class TestGame : public AbstractGame {
private:
	
	Raycast r;
	Block bblock;
	Block bblock2;
	Block bblock3;
	Vector2i velocity;

	MazeGenerator* gen;

	std::vector<std::shared_ptr<Line2i>> lines;
	std::vector<std::shared_ptr<GameKey>> points;

	/* GAMEPLAY */
	

	void handleKeyEvents();
	void update();
	void render();
	void renderUI();
public:
	TestGame();
	~TestGame();
};

#endif