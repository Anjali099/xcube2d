#include "TestGame.h"


TestGame::TestGame() : AbstractGame(), score(0), lives(3), keys(5), gameWon(false), box(5, 5, 30, 30), light(0, 0, 150, 150) {
	TTF_Font* font = ResourceManager::loadFont("res/fonts/arial.ttf", 72);

	

}

TestGame::~TestGame() {

}

void TestGame::handleKeyEvents() {

}

void TestGame::update() {


}



void TestGame::render() {
	gfx->setDrawColor(SDL_COLOR_RED);
	gfx->drawRect(box);
	Block b(2, 2, 2, 2);
	Raycast r(b);
	gfx->drawLine(r.startpos, r.endpos);
	//r.drawBlocks(b);
	//gfx->drawRect(b.boundingbox);
}

void TestGame::renderUI() {

}
//DRAW BLOCKS	