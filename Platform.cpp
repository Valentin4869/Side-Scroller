#include "StdAfx.h"
#include "Platform.h"


Platform::Platform(void)
{
	speed =8;
	height=8*12;
	width=8*20;

	start.x=100;
	start.y=450;
	

	color.R=1;
	color.G=1;
	color.B=1;
	
}

void Platform::Position(float sx, float sy)
{
	start.x=sx;
	start.y=sy;

}

void Platform::ResetVelocity()
{
	
		velocity.y=velocity.x=0;
	
}

void Platform::Draw()
{
	glColor3f(color.R,color.B,color.G);
	glBegin(GL_POLYGON);   

	glVertex2d(start.x,start.y);
	glVertex2d(start.x+width,start.y);

	glVertex2d(start.x+width, start.y+height);
	glVertex2d(start.x, start.y + height);
	

	
	glEnd();

}

void Platform::Move(direction dir)
{
	switch(dir)
	{
	case RIGHT:
		velocity.x=speed;
		break;
	case LEFT:
		velocity.x=-speed;
		break;
	case UP:
		velocity.y=-speed;
		break;
	case DOWN:
		velocity.y=speed;
		break;
	
	}

	

}

void Platform::GrowWidth(float amount)
{

	width+=amount;

	Update();
}
	
void Platform::GrowHeight(float amount)
{
	height+=amount;

	Update();
}



Platform::~Platform(void)
{
}
