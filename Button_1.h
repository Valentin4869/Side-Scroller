#pragma once
#include "Data.h"

class Button_1
{
public:
	
	Point2d start;
	int width, height;
	void Update();
	float Fixed;
	float *Ax;
	float xPos, yPos;
	RGBC color, textcolor;
	char text[20];
	bool MouseHovering;
	bool Clicked;
	void Draw();
	void DrawBorder();

	void Fix(float*);
	void SetPosition(float,float);
	void SetCentre(Point2d);
	void SetCentre(float,float);
	void SetColor(RGBC rgbc){glColor3f(rgbc.R,rgbc.B,rgbc.G);}
	Point2d GetCentre();
	void GetCentre(float&,float&);
	Button_1(float*);
	Button_1(void);
	~Button_1(void);
};

