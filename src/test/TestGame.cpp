#include "TestGame.h"


TestGame::TestGame() : AbstractGame(), bblock(500, 200, 70, 70, SDL_COLOR_AQUA, 1), bblock2(80, 500, 70, 70, SDL_COLOR_AQUA, 1), bblock3(155, 300, 70, 70, SDL_COLOR_AQUA, 1), r(bblock, 10, 10){
	TTF_Font* font = ResourceManager::loadFont("res/fonts/arial.ttf", 72);
	//r.endpos.x = bblock.b.x;
	//r.endpos.y = bblock.y;
	gfx->useFont(font);
	gfx->setVerticalSync(true);
	
	

	r.blockObjects.push_back(bblock);
	r.blockObjects.push_back(bblock2);
	r.blockObjects.push_back(bblock3);
}

TestGame::~TestGame() {

}

void TestGame::handleKeyEvents() {

}

void TestGame::update() {
	//std::cout << r.startpos.x << std::endl; 
	//std::cout << r.endpos.x << std::endl; 
	//std::cout << r.blockObjects.size() << std::endl; // checks size
   
	for (int i = 0; i <= r.blockObjects.size(); i++)
	{
		
		r.drawBlocksArray(bblock);
	}

}


void TestGame::render() { 

	//gfx->drawBlocks(bblock2.boundingbox, bblock2.colour);
	
// made another block and pushed in the vector
	
	for each (Block b in r.blockObjects) {
		
		gfx->setDrawColor(b.colour);
		gfx->drawBlocks(b.boundingbox, b.colour);
		//r.endpos.x = b.x;
		//r.endpos.y = b.y;
		gfx->setDrawColor(SDL_COLOR_AQUA);
		gfx->drawRaycast(b.boundingbox, r.startpos);
		//break;
	}

	
	
	
} 


void TestGame::renderUI() {

	
}
