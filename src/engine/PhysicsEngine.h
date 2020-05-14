#ifndef __PHYSICS_ENGINE_H__
#define __PHYSICS_ENGINE_H__

#include <vector>
#include <memory>
#include <array>
#include "GameMath.h"

static const float DEFAULT_GRAVITY = -1.0f;

class PhysicsObject;

class PhysicsEngine {
	friend class XCube2Engine;
	friend class PhysicsObject;
	friend class Block;
	friend class Raycast;
	private:
		Vector2f gravity;
		PhysicsEngine();

		std::vector<std::shared_ptr<PhysicsObject>> objects;

	public:
		/**
		* Note that gravity is naturally a negative value
		* update interval in seconds
		*/
		void setGravity(float gravityValue, float worldUpdateInterval);
		void update();

		void registerObject(std::shared_ptr<PhysicsObject>);
};
class Block
{	
	friend class XCube2Engine;
	friend class PhysicsEngine;
	friend class Rectangle2;
public:
	int block_type;// 0 for one type and 1 for another (glass) i think
	SDL_Color colour;
	SDL_Rect boundingbox;
	
	//Block();
	//Block(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
	int x, y, w, h;
	Block(int x, int y, int w, int h,SDL_Color,int t);
	

};
class Raycast {
	friend class Block;
	//int x, y;
	//Raycast(int x, int y) : x(x), y(y) {}	
public:
	Line2i raycastLine;
	Point2 startpos;
	Point2 endpos;
	std::vector <Block> blockObjects;
	Raycast(Block b, int x, int y);
	
	void drawBlocksArray(Block a,int size);
    // add block objects and do the raycast
	
};

class PhysicsObject {
	friend class PhysicsEngine;
	protected:
		Point2 center;
		float lX, lY, hlX, hlY;	// lengths and half lengths

		Vector2f force;

		void applyForce(const Vector2f &);
	public:
		PhysicsObject(const Point2 & center, float x, float y);

		Point2 getCenter() { return center; }
		float getLengthX() { return lX; }
		float getLengthY() { return lY; }
		float getHalfLengthX() { return hlX; }
		float getHalfLengthY() { return hlY; }

		bool isColliding(const PhysicsObject & other);
		/**
		* If we have different implementations of engines/gravity
		* this can be very useful
		*/
		virtual void applyGravity(const PhysicsEngine & engine);
		virtual void applyAntiGravity(const PhysicsEngine & engine);
};

#endif