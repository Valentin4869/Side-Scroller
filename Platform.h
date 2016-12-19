#pragma once
#include "Data.h"



class Platform
{
	
public:
	
	float width, height;
	Point2d start;
	Vector2d velocity;
	
	RGBC color;
	

	float speed;
	void Draw();
	
	float GetWidth(){return width;}
	Point2d GetStart(){return start;}
	//For editing:
	void Position(float,float);
	void Move(direction);
	void ResetVelocity();
	void GrowWidth(float);
	void GrowHeight(float);
	void Update(){ start.x+=velocity.x; start.y+=velocity.y; ResetVelocity();}
	Platform(void);
	~Platform(void);
};


struct Coin{

	Point2d centre;
	Texture tex;
	Coin(){tex.height=tex.width=1; centre.x=200; centre.y=200; tex.base=GetBmp("h/coin03.bmp");}
	
};


struct Platform_Data{
	
	Point2d start;
	float width, height;
};