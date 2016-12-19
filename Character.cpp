#include "StdAfx.h"
#include "Character.h"


Character::Character(void)
{
	
	speed=12;	//Movement speed
	facing=1;
	iFB=MOVING;
	dead=false;
	PlatformsContact=0;	//Number of platforms the character is in contact with
	GroundContact=false; //Is the character in contact with the ground(top of the platform)?
	Gravity=0.5*9.8*(0.125);
	//SetFB("h\\en2(100).bmp",1, "h\\en2(200).bmp",1,"h\\en2(300).bmp",1);

//	tex.base=GetBmp("h\\en(100).bmp");
	jumping=false; //Currently jumping?
	contact=false; //Is the character in contact with >=1 platforms?
	Life=3;
	centre.x=350;
	centre.y=100;
	
	sides=20;	//Number of polygon sides.

	length=DEFAULT_LENGTH;	//Polygon(character shape) radius

	color.R=0.6;
	color.G=0.6;
	color.B=0.6;
}

Character::Character(float xpos)
{
	
	Character();
	centre.x=xpos;
}

Enemy::Enemy(void)
{
	speed=6;	//Movement speed
	dead=false;
	visible =false;
	PlatformsContact=0;	//Number of platforms the character is in contact with
	GroundContact=false; //Is the character in contact with the ground(top of the platform)?
	//SetFB("h\\en2(100).bmp",1);
	
	jumping=false; //Currently jumping?
	contact=false; //Is the character in contact with >=1 platforms?
	Life=3;
	centre.x=350;
	centre.y=100;
	
	sides=4;	//Number of polygon sides.

	length=DEFAULT_LENGTH;	//Polygon(character shape) radius

	color.R=0.34;
	color.G=0.34;
	color.B=0.34;

}

Enemy::~Enemy(void)
{}


void Character::Update()
{	

	//Apply movement
	Move();
	
	if(right)
	facing=1;
		
	else if(left)
		facing=0;
		
	

	if(abs(velocity.U)>abs(velocity.D))
	{iFB=JUMPING;}
	else if(abs(velocity.U)<abs(velocity.D))
	{iFB=FALLING;}
	else
		iFB=MOVING;

	for(int i=0; i<3; i++)
		FlipFB(fb[i],facing);
	//Generate points now for movement effects
	GenerateCPoints();	

	//Check if airborne after jump
	if(!contact && velocity.U<0)
	jumping=true;
		
		//If airborne after jump, test for ground contact to cancel upward velocity
		if(jumping)
		{
			if(GroundContact)
			{jumping=false; velocity.U=0;}
		
		}
		
	
	//gravity
		velocity.D+=this->Gravity;

	//update position
	centre.x+=(velocity.R+velocity.L);
	centre.y+=(velocity.U+velocity.D);
}

//void Enemy::Update()
//{	
//
//	//Apply movement
//	Move();
//
//	const unsigned char cc[]="Contact";
//
//	//Generate points now for movement effects
//	GenerateCPoints();	
//
//	//Check if airborne after jump
//	if(!contact && velocity.U<0)
//	 jumping=true;
//		
//		//If airborne after jump, test for ground contact to cancel upward velocity
//		if(jumping )
//			if(GroundContact)
//			{jumping=false; velocity.U=0;}
//		
//
//		
//	
//	//gravity
//	velocity.D+=Gravity;
//
//	//update position
//	centre.x+=(velocity.R+velocity.L);
//	centre.y+=(velocity.U+velocity.D);
//
//}

void Character::Jump()
{
	if(GroundContact)
	{
		velocity.U=-18; 
	}

}


//void Character::Draw()
//{	
//			
//	//cout<<"Centre "<<centre.x<<endl;
//
////	DrawBitmap(centre.x-tex.base->Width/2, centre.y +tex.base->Height/2 ,tex.base,1);
//
//	DrawCPoints();
//	
//	glColor3f(color.R,color.G,color.B);
//	glBegin(GL_POLYGON);
//	
//	for(int i=0; i<sides; i++)
//	glVertex2f(length*cos((i*(360.0/sides)-45)/180.0*PI)+centre.x, length*sin((i*(360.0/sides)-45)/180.0*PI)+centre.y);
//
//	
//	glEnd();
//
//}

void Character::Reposition(direction dir)
{
	//Appropriately reposition character after contact with an object

	switch(dir)
	{

	case RIGHT:
		centre.x= p->start.x-length;
	break;

	case LEFT:
		centre.x= p->start.x+ p->width+length;
	break;

	case UP:
		centre.y= p->start.y+ p->height +length;
		
	break;

	case DOWN:
		centre.y= p->start.y-length;
	break;

	}

}

void Character::Move()
{
	if(right)
	{	if(velocity.R<speed)
		velocity.R+=speed/8;
	}
		else
			if(velocity.R>0)
				velocity.R-=speed/8;
		
	if(left)
	{	if(velocity.L>-speed)
		velocity.L-=speed/8;
	}
		else
			if(velocity.L<0)
				velocity.L+=speed/8;	
	
}




void Character::ResetVelocity(bool b)
{
if(!b)
	velocity.R=velocity.L=0;
else if(b)
	velocity.D=velocity.U=0;

}

void Character::DrawCPoints()
{
	
			glPointSize(5);
			glBegin(GL_POINTS);
			glColor3f(1,0.0,0.0);

		for(int i=0; i<4; i++)			
		glVertex2f(cpoints[i].x,cpoints[i].y);

			glEnd();
}

void Character::GenerateCPoints()
{
for(int i=0; i<4; i++)
		{
			cpoints[i].x=centre.x+ (1.5*length)*cos(2*PI*i/4);
			cpoints[i].y=centre.y+ (1.5*length)*sin(2*PI*i/4);
			glVertex2f(cpoints[i].x,cpoints[i].y);
		}
}

Character::~Character(void)
{

}
