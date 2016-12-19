#pragma once
#include "Data.h"
#include "Platform.h"


class Character{
	
public:	
	
	Velocity velocity;
	
	bool GroundContact;
	bool jumping;
	short iFB;
	Platform* p; //Platforms to interact with
	
	short PlatformsContact;	//Number of platforms in contact with
	//Texture tex;
	
	FrameBuffer fb[3];

	int sides;
	RGBC color;
	short Life;
	Timer timer;
	Timer t;
	bool dead;
	float speed;
	void SetFB(char* pM, int sM, char* pJ, int sJ, char* pF, int sF)
	{
		fb[0].size=sM;
		fb[0].Load(pM);

		fb[1].size=sJ;
		fb[1].Load(pJ);

		fb[2].size=sF;
		fb[2].Load(pF);
	}

	void SetFB(char* p, int s)
	{
		
		for(int i=0; i<3; i++)
		{
			fb[i].size=s;
			fb[i].Load(p);
		}
}

	void DrawCPoints();
	bool CanJump();	//Is the character in position to jump?
	void GenerateCPoints();
	void Reposition(direction);
	float Gravity;
	
	Point2d cpoints[4];
	Point2d centre;
	bool contact;
	bool facing;
	float length;
	bool right,left;	//Which ways to move
	void Draw();
	void Move();
	


	void DetermineFB();
	 void Update();
	void Move(direction);
	float CorrectNetVelocity();
	void Jump();
	void ResetVelocity(bool);
	
	void DetState();


	Character(void);
	Character(float);
	~Character(void);
};

class Enemy: public Character
{
public:
	
	bool visible;

	void TakeDecision(int difficulty){
		
		switch(difficulty)
		{
			
		case 0:
			{
				if(rand()%520 +6 >500)
				left=true;
			else
				left=false;

			if(rand()%5854 -90 <2270)
				right=true;
			else
				right=false;

			if(rand()%1000 <4)
				Jump();
			}

		break;


		}

	}
	
	// void Update();
	
	Enemy(void);
	~Enemy(void);
};

