#include "TestGame.h"


TestGame::TestGame() : AbstractGame(), score(0), lives(3), keys(5), gameWon(false), box(5, 5, 30, 30), light(0, 0, 150, 150), b(2, 2, 2, 2) /*B IS THE BLOCK*/ {
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
	
	Raycast r(b);
	
	r.drawBlocks(b,3);
	gfx->drawRect(b.boundingbox);
	gfx->drawRay(r.startpos, r.endpos);
}

void TestGame::renderUI() {

}
//DRAW BLOCKS	