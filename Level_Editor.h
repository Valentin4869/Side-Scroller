#pragma once

#include"stdafx.h"
#include "Data.h"
#include"Platform.h"
#include <vector>
#include "BmpOps.h"

struct Level_Data{

	int nPlatforms;
	float xBegin, xEnd;

	vector<Platform_Data> pd;

	
	void Draw()
	{
		
	

	   for(int i=0; i<nPlatforms; i++)
	   {
		   glColor3f(1,1,1);
		   glBegin(GL_POLYGON);
		glVertex2d(pd[i].start.x,pd[i].start.y);
		glVertex2d(pd[i].start.x+pd[i].width,pd[i].start.y);

		glVertex2d(pd[i].start.x+pd[i].width, pd[i].start.y+pd[i].height);
		glVertex2d(pd[i].start.x, pd[i].start.y + pd[i].height);
	
		glColor3f(0,1,0);
		glRasterPos2f(pd[i].start.x,pd[i].start.y-5);
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, 65+i);
		
		glEnd();
 
		
	  }
	

}

};
struct Level_Data2{
	
	//General Level data
	float lBegin, lEnd;
	short LevelId;
	Texture_Id EnemyTexture;
	Texture_Id PlatformTexture;
	Texture_Id CoinTexture;
	Texture_Id BackgroundTexture;
	FB_Id EnemyFB;
	

	//Enemy
	vector<Point2d> eCentre;
	int nE;
	//Coin
	vector<Point2d> cCentre;
	int nC;
	//Platforms
	int nP;
	vector<Point2d> pStart;
	vector<float> pWidth; 
	vector<float> pHeight;
};

enum Selected{PLATFORM, WORLD, SELECTOR, ENEMY, COIN};
enum Event{NEWPLATFORM};
enum Purpose{GAME, EDITOR};

short tcounter=0, ecounter=0, ccounter=0;
float A=0, B=800;
float centre=(A+(B-A)/2);
float translation=0;
int pSelector=0, eSelector=0, cSelector=0;

Platform ptemp;
Enemy etemp;
Coin ctemp;

Selected sel=PLATFORM;
Bitmap *lb;
vector<Button_1> EButtons(0);
Texture LETexture;


Level_Data EditorLevel;	
Level_Data2 EditorLevel2; //Destination of level data for saving/ source for loading
Texture_Id EE, EP, EC, EB;
FB_Id EEFB;
FrameBuffer *EnemyFB;
Texture EnemyTexture, PlatformTexture, CoinTexture, BackgroundTexture;
vector<Platform>EPlatforms(0);
vector<Enemy>EEnemies(0);
vector<Coin> ECoins(0);
int LevelBegin, LevelEnd;

void New();
void Delete();

void LoadLevel(Level_Data&);
void ELoadLevel2(Level_Data2);
Level_Data2* CreateLD();

void ChangeTexture();
void LoadLD(Level_Data2&);
void SaveLD(Level_Data2);
void InitLE();
void InitLE(Level_Data2);
void SpLEP (int, int, int);
void SpLES (int, int, int);
void SpLEW (int, int, int);
void SpLEE (int, int, int);
void SpLEC (int, int, int);
void Selection(short a);

Texture ResolveTextureId(Texture_Id texid)
{
	Texture TEXTURE;

	switch(texid)
	{
	case t_00:

		TEXTURE.base=GetBmp("h/texture01.bmp");
		break;

	case t_10:
		TEXTURE.base=GetBmp("h/texture02.bmp");
		break;

	case t_20:
		TEXTURE.base=GetBmp("h/texture03.bmp");
		break;

	case t_30:
		TEXTURE.base=GetBmp("h/texture04.bmp");
		break;

	case e_00:
		TEXTURE.base=GetBmp("h/en(100).bmp");
		break;

	case e_10:
		TEXTURE.base=GetBmp("h/en2(100).bmp");
		break;

	case e_20:
		TEXTURE.base=GetBmp("h/en3(100).bmp");
		break;

	case c_00:
		TEXTURE.base=GetBmp("h/coin(100).bmp");
		break;

	case c_10:
		TEXTURE.base=GetBmp("h/coin2(100).bmp");
		break;

	case c_20:
		TEXTURE.base=GetBmp("h/coin3(100).bmp");
		break;
	}

	return TEXTURE;
}
FrameBuffer* ResolveFB(FB_Id fbid)
{
	FrameBuffer *FB=new FrameBuffer[3];

	switch(fbid)
	{
	case fb_01:
		FB[0].size=1;
		FB[0].Load("h/en(100).bmp");

		FB[1].size=1;
		FB[1].Load("h/en(200).bmp");

		FB[2].size=1;
		FB[2].Load("h/en(300).bmp");
		break;

	case fb_02:
		FB[0].size=1;
		FB[0].Load("h/en2(100).bmp");

		FB[1].size=1;
		FB[1].Load("h/en2(200).bmp");

		FB[2].size=1;
		FB[2].Load("h/en2(300).bmp");
		break;

	case fb_03:

		break;

	case fb_04:

		break;
	}

	return FB;
}


Level_Data2* CreateLD()
{
	Level_Data2 *LD=new Level_Data2;

	LD->lBegin=LevelBegin;
	LD->lEnd=LevelEnd;
	LD->LevelId=9;

	LD->EnemyTexture=EE;
	LD->PlatformTexture=EP;
	LD->CoinTexture=EC;
	LD->BackgroundTexture=EB;
	LD->EnemyFB=EEFB;
	
	//Enemy
	

	for(int i=0; i<EEnemies.size(); i++)
		LD->eCentre.push_back(EEnemies[i].centre);

	//Coin
	for(int i=0; i<ECoins.size(); i++)
		LD->cCentre.push_back(ECoins[i].centre);

	
	//Platforms
	
	for(int i=0; i< EPlatforms.size(); i++)
	{
		LD->pStart.push_back(EPlatforms[i].start);
		LD->pWidth.push_back(EPlatforms[i].width);
		LD->pHeight.push_back(EPlatforms[i].height);
	}


	return LD;
}

void ELoadLevel2(Level_Data2 ld)
{
	
	EPlatforms.clear();
	ECoins.clear();
	EEnemies.clear();

	for(int i=0; i<ld.nP; i++)
	{
		
		ptemp.start=ld.pStart[i];
		ptemp.height=ld.pHeight[i];
		ptemp.width=ld.pWidth[i];

		EPlatforms.push_back(ptemp);
	}

	for(int i=0; i<ld.nC; i++)
	{
		
		ctemp.centre=ld.cCentre[i];
		ECoins.push_back(ctemp);
	}

	for(int i=0; i<ld.nE; i++)
	{
		
		etemp.centre=ld.eCentre[i];
		EEnemies.push_back(etemp);
	}


}

void SaveLD(Level_Data2 ld)
{
	int size=0;
	int nC, nE, nP;
	char path[200];

	GetSaveFileNameA( &GetOFN(path) );
	
	cout<<"Saving as "<<path<<endl;
	remove(path);
	ofstream file(path,ios::binary  | ios::app);


	
	FB_Id EnemyFB;

	//General
	size+=sizeof(float)*2; //lBegin, lEnd
	size+=sizeof(short);
	size+=sizeof(Texture_Id)*4 + sizeof(FB_Id);

	//Platforms
	size+= ld.pStart.size()*(sizeof(int) + sizeof(float)*2 + sizeof(float) + sizeof(float));//nP*(int, Point2d(float, float), float, float)
	
	//Coins
	size+=ld.cCentre.size()*(sizeof(int) + sizeof(float)*2);

	//Enemy
	size+=ld.eCentre.size()*(sizeof(int) + sizeof(float)*2);

	
	//-------------------Write to file-------------------

	//General
	file.write(reinterpret_cast<char*>(&ld.lBegin),sizeof(float));
	file.write(reinterpret_cast<char*>(&ld.lEnd),sizeof(float));
	file.write(reinterpret_cast<char*>(&ld.LevelId),sizeof(short));
	file.write(reinterpret_cast<char*>(&ld.EnemyTexture),sizeof(Texture_Id));
	file.write(reinterpret_cast<char*>(&ld.PlatformTexture),sizeof(Texture_Id));
	file.write(reinterpret_cast<char*>(&ld.CoinTexture),sizeof(Texture_Id));
	file.write(reinterpret_cast<char*>(&ld.BackgroundTexture),sizeof(Texture_Id));

	cout<<"Saved texture: "<<ld.PlatformTexture<<endl;

	//Coins
	nC=ld.cCentre.size();
	file.write(reinterpret_cast<char*>(&nC),sizeof(int));

		for(int i=0; i<ld.cCentre.size(); i++)
		{
			file.write(reinterpret_cast<char*>(&ld.cCentre[i].x),sizeof(float));
			file.write(reinterpret_cast<char*>(&ld.cCentre[i].y),sizeof(float));
		}

	//Enemy
		nE=ld.eCentre.size();
		file.write(reinterpret_cast<char*>(&nE),sizeof(int));

		for(int i=0; i<ld.eCentre.size(); i++)
		{
			file.write(reinterpret_cast<char*>(&ld.eCentre[i].x),sizeof(float));
			file.write(reinterpret_cast<char*>(&ld.eCentre[i].y),sizeof(float));
		}

	//Write the data for each platform
		nP=ld.pStart.size();
		file.write(reinterpret_cast<char*>(&nP),sizeof(int));

		for(int i=0; i<ld.pStart.size(); i++)
		{
			file.write(reinterpret_cast<char*>(&ld.pStart[i].x),sizeof(float));
			file.write(reinterpret_cast<char*>(&ld.pStart[i].y),sizeof(float));
			file.write(reinterpret_cast<char*>(&ld.pHeight[i]),sizeof(float));
			file.write(reinterpret_cast<char*>(&ld.pWidth[i]),sizeof(float));
		}

	cout<<"Save Complete! Size: "<<size<<endl;
	file.close();
}

void LoadLD(Level_Data2& ldt, char* path)
{
	
	Level_Data2 ld;
	int size=0;
	Point2d ftemp;
	float wtemp, htemp;
	cout<<"Loading "<<path<<endl;

	ifstream file(path,ios::binary);

	//General
	size+=sizeof(float)*2; //lBegin, lEnd
	size+=sizeof(short);
	size+=sizeof(Texture_Id)*4 + sizeof(FB_Id);
	
	//-------------------Read from file-------------------

	//General
	file.read(reinterpret_cast<char*>(&ld.lBegin),sizeof(float));
	file.read(reinterpret_cast<char*>(&ld.lEnd),sizeof(float));
	file.read(reinterpret_cast<char*>(&ld.LevelId),sizeof(short));
	file.read(reinterpret_cast<char*>(&ld.EnemyTexture),sizeof(Texture_Id));
	file.read(reinterpret_cast<char*>(&ld.PlatformTexture),sizeof(Texture_Id));
	file.read(reinterpret_cast<char*>(&ld.CoinTexture),sizeof(Texture_Id));
	file.read(reinterpret_cast<char*>(&ld.BackgroundTexture),sizeof(Texture_Id));
	
	cout<<"Loaded texture: "<<ld.PlatformTexture<<endl;

	//Coins
file.read(reinterpret_cast<char*>(&ld.nC),sizeof(int));

		for(int i=0; i<ld.nC; i++)
		{
			file.read(reinterpret_cast<char*>(&ftemp.x),sizeof(float));
			file.read(reinterpret_cast<char*>(&ftemp.y),sizeof(float));
			ld.cCentre.push_back(ftemp);
		}

	//Enemy
	file.read(reinterpret_cast<char*>(&ld.nE),sizeof(int));
		

		for(int i=0; i<ld.nE; i++)
		{
			file.read(reinterpret_cast<char*>(&ftemp.x),sizeof(float));
			file.read(reinterpret_cast<char*>(&ftemp.y),sizeof(float));
			ld.eCentre.push_back(ftemp);
		}

	//Write the data for each platform
file.read(reinterpret_cast<char*>(&ld.nP),sizeof(int));

for(int i=0; i<ld.nP; i++)
		{
			file.read(reinterpret_cast<char*>(&ftemp.x),sizeof(float));
			file.read(reinterpret_cast<char*>(&ftemp.y),sizeof(float));
			ld.pStart.push_back(ftemp);

			file.read(reinterpret_cast<char*>(&htemp),sizeof(float));
			file.read(reinterpret_cast<char*>(&wtemp),sizeof(float));
			ld.pHeight.push_back(htemp);
			ld.pWidth.push_back(wtemp);
		}

		size+=ld.nE*(sizeof(int) + sizeof(float)*2);
		size+=ld.nP*(sizeof(int) + sizeof(float)*2 + sizeof(float) + sizeof(float));//nP*(int, Point2d(float, float), float, float)
		size+=ld.nC*(sizeof(int) + sizeof(float)*2);

	cout<<"Load Complete! Size: "<<size<<endl;
	cout<<"Platforms: "<<ld.pStart.size()<<endl;
	cout<<"Coins: "<<ld.nC<<endl;
	cout<<"Enemies: "<<ld.nE<<endl;
	cout<<"Begin: "<<ld.lBegin<<endl;
	cout<<"End: "<<ld.lEnd<<endl;


	ldt=ld;
	file.close();
	
}

void LoadLD(Level_Data2& ld)
{
	
	if(MessageBoxA(FindWindowA(0,"Game_AI"),"Would you like to edit an existing level?",0,MB_YESNO)==IDNO)
	{LoadLD(EditorLevel2,"defaultLD.ld");}
	else
	{
		char path[200];
	GetOpenFileNameA(&GetOFN(path));
	if(FindStr(path,".ld")==-1)
	{MessageBoxA(FindWindowA(0,"Game_AI"),"Invalid file!",0,MB_OK); LoadLD(EditorLevel2,"defaultLD.ld");}
	else
	LoadLD(EditorLevel2,path);
	}
}


void InitLE()
{
	LoadLD(EditorLevel2);
	ELoadLevel2(EditorLevel2);
	//LoadLevel(EditorLevel);

		EP=t_20;
		EE=e_00;
		EC=c_10;
		EnemyFB=ResolveFB(EEFB);
	PlatformTexture=ResolveTextureId(EP);
	EnemyTexture=ResolveTextureId(EE);
	CoinTexture=ResolveTextureId(EC);
}

void DrawCircle(float x, float y, float radius)
{
	glBegin(GL_LINES);
	short d=6;
	glColor3f(0,1,0);
	

	for(int j=0; j<200; j++)
	{
		glColor4f(0,1,0,0);
		//if(radius<20)
		//	continue;
		for(int i=0; i<d; i++)
		{
			glVertex2f(radius*cos(i*2*PI/d) + x, radius*sin(i*2*PI/d) + y);
			glVertex2f(radius*cos((i+1)*2*PI/d) + x, radius*sin((i+1)*2*PI/d) + y);
		}

		
	}
	glEnd();

}

void PlatformsFromLD(Level_Data ld, vector<Platform> &p)
{
	//Fills a Platform vector with info from Level_Data
	
	Platform pbuff;


	for(int i=0; i<ld.nPlatforms; i++)
	{
		pbuff.height=ld.pd[i].height;	
		pbuff.width=ld.pd[i].width;
		pbuff.start=ld.pd[i].start;

		p.push_back(pbuff);
	}
	
	cout<<"Now size= "<<p.size()<<endl;
}


char* ToPChar(short num)
{
	static char chnum[]="Level00.txt";

	chnum[6]=num%10+48;
	num/=10;
	chnum[5]=num%10+48;
	for(int i=0; i<12; i++)
	cout<<chnum[i];
	
	return chnum;

}

void DrawElements()
{
	//enemies
	
	for(int i=0; i<EEnemies.size(); i++)
	{
		EEnemies[i].Gravity=0;
		EEnemies[i].Update();

		DrawBitmap(EEnemies[i].centre.x-EnemyTexture.base->Width/2, EEnemies[i].centre.y +EnemyTexture.base->Height/2,EnemyTexture.base,1);
				
	}

	for(int i=0; i<ECoins.size(); i++)
	{
		
		DrawTexture(ECoins[i].centre.x-CoinTexture.base->Width/2, ECoins[i].centre.y+CoinTexture.base->Height/2, CoinTexture,0);
		
	}
	
	
	//DrawBitmap(100,200,lb,1);
	
	for(int i=0; i<int(EPlatforms.size());i++)
		{
			EPlatforms[i].Update();
			 PlatformTexture.height=EPlatforms[i].height/PlatformTexture.base->Height+1;
			PlatformTexture.width=EPlatforms[i].width/PlatformTexture.base->Width+1;
			DrawTexture(EPlatforms[i].start.x,EPlatforms[i].start.y + PlatformTexture.base->Height, PlatformTexture,0);
		

		glColor3f((float).8,(float).8,(float)0.0);
		glRasterPos2f(EPlatforms[i].start.x,EPlatforms[i].start.y-5);
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, 65+i);

		
		}
	for(int i=0; i<EButtons.size(); i++)
	{
		EButtons[i].Update();
		EButtons[i].Draw();
	}
}

void LoadLevel(Level_Data &ld)
{
	//Fill a Level_Data ld with info from file
	short lvlnum;
	cout<<"Level Number: ";
	cin>>lvlnum;
	char* path=ToPChar(lvlnum);
	
	if(lvlnum==0)
	{
		ld.nPlatforms=0;
		return;

	}
	else{
	ifstream file(path, ios::binary);
	
	//Temporarily hold data for transfer to vector/array
	Platform_Data pbuff;
	
	//Get number of platforms
	file.read(reinterpret_cast<char*>(&ld.nPlatforms),4);
	
	cout<<"\nNumber of platforms: "<<ld.nPlatforms<<endl;
	//Read Beginning and ending of level
	file.read(reinterpret_cast<char*>(&ld.xBegin),sizeof(float));
	file.read(reinterpret_cast<char*>(&ld.xEnd),sizeof(float));
	
	cout<<"B: "<<ld.xBegin<<", E: "<<ld.xEnd<<endl;

	
		//Fetch data from file into pbuff, then fill vector/array with it
	for(int i=0; i<ld.nPlatforms; i++)
		{
			file.read(reinterpret_cast<char*>(&pbuff),sizeof(Platform_Data));	
		
			ld.pd.push_back(pbuff);
		
			cout<<i<<": x="<< ld.pd[i].start.x<<", y= "<<ld.pd[i].start.y<<endl;
		}
	}
	PlatformsFromLD(ld,EPlatforms);
	
}
//
//short* LoadLevelList()
//{
//	ifstream LevelList("LevelList.txt", ios::binary);
//	short buff;	//temporary storage
//	short* list;//array of level numbers
//
//	//Get number of levels
//	LevelList.read(reinterpret_cast<char*>(&buff), 8);
//
//	list= new short[buff];
//
//	//Fill list with each level's number
//
//	for(int i=0; i<buff; i++)
//	{
//		LevelList.read(reinterpret_cast<char*>(&list[i]),sizeof(short));
//		cout<<"Loaded level "<<list[i]<<endl;
//	}
//
//	return list;
//}
//
//void SaveLevelList(char* list)
//{
//	ofstream LevelList("LevelList.txt", ios::binary | ios::app);
//	
//
//
//}



void SaveLevel(Level_Data ld)
{
	short lvlnum;
	cout<<"Level Number: ";
	cin>>lvlnum;
	char* path=ToPChar(lvlnum);

	remove(path);

	ofstream file(path,ios::binary  | ios::app);
	cout<<"Saving..."<<path<<endl;
	ld.nPlatforms=EPlatforms.size();
	
	

	int size= 4 + 2*sizeof(float) + (sizeof(Platform_Data)*ld.nPlatforms);//np=4, xbegin + xend...
	
	//write Number of platforms
	file.write(reinterpret_cast<char*>(&ld.nPlatforms),sizeof(int));
	
	//Write Level begin and end
	file.write(reinterpret_cast<char*>(&ld.xBegin),sizeof(float));
	
	file.write(reinterpret_cast<char*>(&ld.xEnd),sizeof(float));
	
	cout<<"B: "<<ld.xBegin<<", E: "<<ld.xEnd<<endl;

	Platform_Data pdbuff;

	ld.pd.clear();

	//Write the data for each platform
	for(int i=0; i<ld.nPlatforms; i++)
	{
		pdbuff.height=EPlatforms[i].height;
		pdbuff.width=EPlatforms[i].width;
		pdbuff.start=EPlatforms[i].start;

		ld.pd.push_back(pdbuff);
		
		cout<<"currentsize: "<<ld.pd.size()<<endl;
		file.write(reinterpret_cast<char*>(&ld.pd[i]),sizeof(Platform_Data));

		cout<<i<<", x:"<<ld.pd[i].start.x<<endl;
		cout<<i<<", y:"<<ld.pd[i].start.y<<endl;
		cout<<i<<", ax:"<<EPlatforms[i].start.x<<endl;
		cout<<i<<", ay:"<<EPlatforms[i].start.y<<endl;
	}

	cout<<"Size: "<<size<<endl;
}


void Highlight()
{
	switch (sel)
	{
	case PLATFORM:
			{
				DrawCircle(EPlatforms[pSelector].start.x,EPlatforms[pSelector].start.y,15);
				/*if(EPlatforms.empty())return;

				cout<<"Hilighting platform "<<pSelector<<endl;
				glLineWidth(2);
	
				glBegin(GL_LINES);
				glColor3f((float)0.0,(float).8,(float)0.0);
	
				glVertex2f(EPlatforms[pSelector].start.x,EPlatforms[pSelector].start.y);
				glVertex2f(EPlatforms[pSelector].start.x+EPlatforms[pSelector].GetWidth(),EPlatforms[pSelector].start.y);
				glEnd();*/
			}
		break;

	case ENEMY:
		DrawCircle(EEnemies[eSelector].centre.x,EEnemies[eSelector].centre.y,20);
		break;

		case COIN:
		DrawCircle(ECoins[cSelector].centre.x,ECoins[cSelector].centre.y,20);
		break;
	default:
		break;
	}
}


void ScreenPrint(char* str)
 {
	 for(int i=0; i<short(strlen(str));i++)
		{
		glColor3f(1,0,0);
		glRasterPos2f(350+(GLfloat)i*8,40);
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str[i]);
		}
}

//void SpLEE( int k, int x, int y ) {}



void DispLE()
{
	
	    glClear(GL_COLOR_BUFFER_BIT);
		
		
		DrawElements();
		//DrawCircle(100,200,50);
	
		
		 switch(sel)
	 {

	 case SELECTOR:
		 glutSpecialFunc(SpLES);
		 ScreenPrint("Selector");
		
		 break;

	 case WORLD:
		 glutSpecialFunc(SpLEW);
		 ScreenPrint("World");
		 break;

	 case PLATFORM:
		 glutSpecialFunc(SpLEP);
		 ScreenPrint("Platform");
		 break;

	case ENEMY:
		 glutSpecialFunc(SpLEE);
		 ScreenPrint("Enemy");
		 break;

	case COIN:
		{
		 glutSpecialFunc(SpLEC); 
		 ScreenPrint("Coin");
		 break;
		}
	default:
		break;
	 }
		
		static int counter=0;
		static bool gB=false, gA=false;
		centre=(A+(B-A)/2);
		
		float point=EPlatforms[pSelector].start.x+ 
			(EPlatforms[pSelector].start.x+EPlatforms[pSelector].width-EPlatforms[pSelector].start.x)/2;
		

		if(sel==SELECTOR || sel==PLATFORM)
			{
				if(point>=B)
			
				{
				counter=100;
				gB=true;
			
				}

			else if(point<=A)
			{
				counter=100;
				gA=true;
			}
		
		
			//smooth translation
			if(counter>0)
			{
				if(gB)
				{
					translation+=30;
					if(translation>=point-centre)
					{counter=0; gB=false;}
				}
				else if(gA)
					{
						translation-=30;
						if(translation<=point-centre)
						{counter=0; gA=false;}

					}
			}
		}
		 glTranslatef(-translation,0,0);
		 A+=translation; B+=translation;
		 
		translation=0;
		
		glPointSize(3);
		glBegin(GL_POINTS);

		glColor3f(1,0,0);
		glVertex2f(A+2,340);

		glColor3f(0,1,0);
		glVertex2f(B-2,340);

		glColor3f(0,0,1);
		glVertex2f(A+(B-A)/2,340);

		 Highlight();
		
		glEnd();

		
		glFlush();
        glutSwapBuffers(); 
	

}

  void KbLE ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	
  switch ( key ) 
	{
  case 'n':
	  New();
	  break;
  /*case 'n':
	  if(EPlatforms.empty())
	  {EPlatforms.push_back(ptemp);}
	  
	  else
		 EPlatforms.push_back(EPlatforms.back());

	  pSelector=EPlatforms.size()-1;
	  break;*/

	   case ']':
	 Selection(1);
	  break;
  case '[':
	 Selection(-1);

	  break;
  case '/':
	  if(sel==PLATFORM)
	 EPlatforms[pSelector].GrowHeight(8);
	  break;
  case '.':
	  if(sel==PLATFORM)
	 EPlatforms[pSelector].GrowHeight(-8);
	  break;

	case ';':
		if(sel==PLATFORM)
	 EPlatforms[pSelector].GrowWidth(-8);
	  break;

	case '\'':
		if(sel==PLATFORM)
	 EPlatforms[pSelector].GrowWidth(8);
	  break;

	case '-':
		ChangeTexture();
		
	  break;

  case 'x':
	  sel=PLATFORM;
	  break;
  case 's':

	  SaveLD(*CreateLD());
	  cout<<"Level saved.\n";
	  break;

	case 'l':
		LoadLD(EditorLevel2);
	  ELoadLevel2(EditorLevel2);
		pSelector=0;
		break;

	case 'w':
		sel=WORLD;
		break;

	
	case 'v':
		sel=COIN;
		if(ECoins.empty())
			New();
	 break;

	 case 'c':
		 sel=ENEMY;
		 if(EEnemies.empty())
			 New();
		 break;

	 case 127:
		 Delete();
		break;
	 break;

	case 'b':
		LevelBegin=centre;
		cout<<"Begin point: "<<centre<<endl;
	break;
	
	

	case 'e':
		LevelEnd=centre;
		cout<<"End point: "<<centre<<endl;
	break;

    default:  
      break;
	}

	cout<<"Left function\n";
}

void New()
{

	 switch(sel)
	 {

	
	 case PLATFORM:
		 { 
			 if(EPlatforms.empty())
		  {EPlatforms.push_back(ptemp);}
	  
		 else
		 {EPlatforms.push_back(EPlatforms[pSelector]);}

			pSelector=EPlatforms.size()-1;
			break;
	     }
	case ENEMY:
		
			 if(EEnemies.empty())
			 EEnemies.push_back(etemp);
	  
			 else
			 EEnemies.push_back(EEnemies[eSelector]);

		 eSelector=EEnemies.size()-1;
		 sel=ENEMY;
		 break;
		

	case COIN:
		if(ECoins.empty())
			 ECoins.push_back(ctemp);
	  
			 else
			ECoins.push_back(ECoins[cSelector]);

		 cSelector=ECoins.size()-1;
		 sel=COIN;
		break;
		
	 }

}


void Delete()
{

	 switch(sel)
	 {

	
	 case PLATFORM:
		 { 
			 if(EPlatforms.size()>1)
			 {
				 
				 EPlatforms.erase(EPlatforms.begin() + pSelector);

				 pSelector--;

				 pSelector==-1?
				pSelector=EPlatforms.size()-1
				:
				pSelector%=EPlatforms.size(); 

				 if(pSelector<0)
					sel=WORLD;
			 }
			break;
	     }

	case ENEMY:
		
		 { 
			 if(!EEnemies.empty())
			 {
				 EEnemies.erase(EEnemies.begin() + eSelector);

			eSelector--;
			
			eSelector==-1?
				eSelector=EEnemies.size()-1
				:
				eSelector%=EEnemies.size(); 

			if(eSelector<0)
				sel=WORLD;

			 }
			break;
	     }
		

	case COIN:
		 { 
			 if(!ECoins.empty())
			 {
	  
				 ECoins.erase(ECoins.begin() + cSelector);

			cSelector--;

			cSelector==-1?
				cSelector=ECoins.size()-1
				:
				cSelector%=ECoins.size(); 

			if(cSelector<0)
				sel=WORLD;
			 }
			break;
	     }
	 }

}
void Selection(short a)
{

	 switch(sel)
	 {

	
	 case PLATFORM:
		 
			 if(!EPlatforms.empty())
		 { 
			 
			pSelector+=a; 
			
				pSelector==-1?
				pSelector=EPlatforms.size()-1
				:
				pSelector%=EPlatforms.size(); 

		 break;
		 }
	     
	case ENEMY:
		 if(!EEnemies.empty())
		 { 
			
			 eSelector+=a; 
			
				eSelector==-1?
				eSelector=EEnemies.size()-1
				:
				eSelector%=EEnemies.size(); 

		 break;
		 }

	case COIN:
		 if(!ECoins.empty())
		 { 
			 
			 cSelector+=a; 
			
				cSelector==-1?
				cSelector=ECoins.size()-1
				:
				cSelector%=ECoins.size(); 
		
		break;
		 }
		
			
		
	 }

}
 void SpLEP ( int k, int x, int y ) 
 {


	 switch ( k ) 
	{
  case GLUT_KEY_UP:     
	
	 EPlatforms[pSelector].Move(UP);
		break;
  
  case GLUT_KEY_DOWN: 
		EPlatforms[pSelector].Move(DOWN);
		break;

  case GLUT_KEY_RIGHT:    
	  EPlatforms[pSelector].Move(RIGHT);  
		break;
	
	case GLUT_KEY_LEFT: 
		EPlatforms[pSelector].Move(LEFT);
		break;
    
	}
		
 }

 void SpLEW ( int k, int x, int y ) 
 {

	 switch ( k ) 
	{
  
  case GLUT_KEY_RIGHT:    
	   translation=35;
		break;
	
	case GLUT_KEY_LEFT: 
		 translation=-35;
		break;
	}

 }
 
 void SpLES ( int k, int x, int y ) 
 {
	 switch ( k ) 
	{
  
   case GLUT_KEY_RIGHT:    
	 if(pSelector<int(EPlatforms.size())-1)
		 pSelector++;
		break;
	
	case GLUT_KEY_LEFT: 
		 if(pSelector>0)
			 pSelector--;
		break;
	}

 }

 void SpLEE ( int k, int x, int y ) 
 {
 
 
	 float amount=18;

	 switch ( k ) 
	{
  
   case GLUT_KEY_RIGHT:    
	  
	   EEnemies[eSelector].centre.x+=amount;
	 
		break;
	
	case GLUT_KEY_LEFT: 
	 EEnemies[eSelector].centre.x-=amount;
		break;

	case GLUT_KEY_UP:    
	  EEnemies[eSelector].centre.y-=amount;
		break;
	
	case GLUT_KEY_DOWN: 
		 EEnemies[eSelector].centre.y+=amount;
		break;
	}

 

}

 void SpLEC (int k, int x, int y)
 {

	 float amount=6;
	
	 switch ( k ) 
	{
  
   case GLUT_KEY_RIGHT:    
	  
	   ECoins[cSelector].centre.x+=amount;
	 
		break;
	
	case GLUT_KEY_LEFT: 
	 ECoins[cSelector].centre.x-=amount;
		break;

	case GLUT_KEY_UP:    
	  ECoins[cSelector].centre.y-=amount;
		break;
	
	case GLUT_KEY_DOWN: 
		 ECoins[cSelector].centre.y+=amount;
		break;
	}



 }

 void idLE()
 {	glutPostRedisplay();
 
 }
	 

 
 
 void EMousePos(int x, int y)
{
	
	 for(int i=0; i<EButtons.size(); i++)
		{

			if(
				 (x + A)<= (EButtons[i].start.x + EButtons[i].width) && (x + A)>= (EButtons[i].start.x)
				&&
				 (y)<= (EButtons[i].start.y + EButtons[i].height) && (y)>= (EButtons[i].start.y)
			  )	
			EButtons[i].MouseHovering=true;
	
			else
				EButtons[i].MouseHovering=false;

		}
}


 void EMouseFunc(int button, int state,int x, int y)
 {

	 for(int i=0; i<EButtons.size(); i++)
		{
			if(EButtons[i].MouseHovering)
			{
			 if(state==GLUT_DOWN && button==GLUT_LEFT_BUTTON)
				 EButtons[i].Clicked=true;
			 else
				 EButtons[i].Clicked=false;
			 break;
			}

		}
 }

 OPENFILENAMEA GetOFN(char* filep)
{

	OPENFILENAMEA ofn2;
	ZeroMemory( &ofn2 , sizeof( ofn2));
	ofn2.lStructSize = sizeof ( ofn2 );

	ofn2.hwndOwner = FindWindow(0,L"Game_AI") ;
	ofn2.lpstrFile = filep;
	ofn2.lpstrFile[0] = '\0';
	ofn2.nMaxFile = 200;
	ofn2.lpstrFilter = "Level Data\0*.LD\0";
	ofn2.nFilterIndex =1;
	ofn2.lpstrFileTitle = NULL ;
	ofn2.nMaxFileTitle = 0 ;
	ofn2.lpstrInitialDir="C:\\Users\\Dell\\Documents\\Visual Studio 2010\\Projects\\Game_AI\\Game_AI\0" ;
	ofn2.Flags = OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST ;

	return ofn2;

}

 void ChangeTexture()
 {
		switch(sel)
		{
		case PLATFORM:
			EP=Texture_Id(t_00 + (EP + ++tcounter)%4);
			PlatformTexture=ResolveTextureId(EP);

			break;

		case ENEMY:
			EE=Texture_Id(e_00 + ( EE+ ++ecounter)%3);
			EnemyTexture=ResolveTextureId(EE);
			break;

		case COIN:
			EC=Texture_Id(c_00 + ( EC+ ++ccounter)%3);
			CoinTexture=ResolveTextureId(EC);
			break;
		}

 }