#include "TestGame.h"


TestGame::TestGame() : AbstractGame(), score(0), lives(3), keys(5), gameWon(false), box(5, 5, 30, 30), light(0, 0, 150, 150),
bblock(50, 50, 30, 30,SDL_COLOR_AQUA,1) /*B IS THE bblock*/ {
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
	Raycast r(bblock, 110, 300);
	r.drawBlocksArray(bblock, 4);
	gfx->drawPoint(r.startpos);
	gfx->drawRect(box);
	
	for (auto b: r.blockObjects){

		gfx->drawRect(&b.boundingbox);
	}
	gfx->drawRay(r.startpos, r.endpos);
}

void TestGame::renderUI() {

}
