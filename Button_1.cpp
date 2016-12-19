#include "StdAfx.h"
#include "Button_1.h"



Button_1::Button_1(float* ax)
{
	
Fixed=true;
Ax=ax;
start.x=xPos + *Ax;
start.y=300;
start.x=200;
xPos=100;
yPos=300;
	height=30;
	color.B=1;
	color.G=1;
	color.R=1;
	MouseHovering=false;
	textcolor.B=0;
	textcolor.G=0;
	textcolor.R=0;

//	strncpy(text,"tdfghgfG",19);
	width=10*strlen(text);
	Update();
	
	
	
	
}

void Button_1::Fix(float* ax)
{
	Button_1();
	Fixed=true;
	Ax=ax;
}

Button_1::Button_1()
{

Fixed=false;
start.y=300;
start.x=200;
xPos=100;
yPos=300;
	height=30;
	color.B=1;
	color.G=1;
	color.R=1;
	MouseHovering=false;
	textcolor.B=0;
	textcolor.G=0;
	textcolor.R=0;

//	strncpy(text,"tdfghgfG",19);
	width=10*strlen(text);
	Update();

}


void Button_1::SetPosition(float xpos, float ypos)
{
	xPos=xpos;
	yPos=ypos;

}

void Button_1::Update()
{
	if(Fixed)
	{
		start.x=xPos+ *Ax;
	
	}
	
	cout<<"At "<<start.x<<endl;

	if(MouseHovering)
		color.G=0.65;
	else
		color.G=1.0;
	
	if(Clicked)
		{
			color.R=0.5;
			color.G=0.5;
			color.B=0.5;
			textcolor.B=1;
			textcolor.G=1;
			textcolor.R=1;
		}
	else
		{
			color.R=1;
			//color.G=1;
			color.B=1;
			textcolor.B=0;
			textcolor.G=0;
			textcolor.R=0;
		}

}

Button_1::~Button_1(void)
{
	

}

void Button_1::Draw()
{
	
	SetColor(color);
	glBegin(GL_POLYGON);

	glVertex2d(start.x,start.y);
	glVertex2d(start.x+width,start.y);

	glVertex2d(start.x+width, start.y+height);
	glVertex2d(start.x, start.y + height);

	glEnd();


	SetColor(textcolor);
	glRasterPos2i(start.x +6, start.y+height/2+3);
	
     for (int i = 0; i < strlen (text); i++)
          glutBitmapCharacter (GLUT_BITMAP_8_BY_13, text[i]);
}

