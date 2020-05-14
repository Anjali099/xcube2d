#include "PhysicsEngine.h"
#include "GraphicsEngine.h"

PhysicsObject::PhysicsObject(const Point2 & center, float x, float y)
: center(center), lX(x), lY(y), hlX(x / 2.0f), hlY(y / 2.0f), force(0.0f, 0.0f) {}

bool PhysicsObject::isColliding(const PhysicsObject & other) {
    Rectf r1 = { center.x - hlX, center.y - hlY, lX, lY };
    Rectf r2 = { other.center.x - other.hlX, other.center.y - other.hlY, other.lX, other.lY };

	return r1.intersects(r2);
}

void PhysicsObject::applyForce(const Vector2f & v) {
	force = v;
}

void PhysicsObject::applyGravity(const PhysicsEngine & engine) {
	center += engine.gravity;
}

void PhysicsObject::applyAntiGravity(const PhysicsEngine & engine) {
	center -= engine.gravity;
}

/* PHYSICS ENGINE */

PhysicsEngine::PhysicsEngine() : gravity(Vector2f(0, DEFAULT_GRAVITY)) {}

void PhysicsEngine::setGravity(float val, float interval) {
	gravity = Vector2f(0, val * interval);
}

void PhysicsEngine::registerObject(std::shared_ptr<PhysicsObject> obj) {
	objects.push_back(obj);
}

void PhysicsEngine::update() 
{

}


void Raycast::drawBlocksArray(Block a,int size)
{
	
	Raycast::blockObjects.size() == size;
	//ree

	for (int i = 0; i < Raycast::blockObjects.size(); i++)
	{
		
		if (i % 2 == 0)
		{
			//set block type to glass change block type and colour
			a.block_type == 1;
			a.colour = SDL_COLOR_AQUA; 
			blockObjects.push_back(a); // puts my blocks in an array
		}
		else
		{
			a.block_type == 0;
			a.colour = SDL_COLOR_PINK;
			blockObjects.push_back(a); // puts my blocks in an array
		}
		// make the bb blocks all next to another
		 
	}
	a.boundingbox.x += 1;
	a.boundingbox.y += 1;
}
Raycast::Raycast(Block b,int x,int y) {

	//*insert raycast code here* https://lodev.org/cgtutor/raycasting.html
	startpos.x = x;     //(0,100) start position
	startpos.y = y;

	endpos.x = b.boundingbox.x;
	endpos.y = b.boundingbox.y;

	raycastLine = Line2i(startpos, endpos); // should draw a line from start postion(5,10) to endpos


}

Block::Block(int x, int y, int w, int h, SDL_Color c, int t)
{
	x = boundingbox.x;
	y = boundingbox.y;
	w = boundingbox.w;
	h = boundingbox.h;

	c = colour;
	t = block_type;

}
