#pragma once

#include "stdafx.h"
#include "Data.h"
#include "Game.h"
#include "Level_Editor.h"

Bitmap* b1, *bh;
Bitmap *b1t, *b2t, *b3t;
char *WTitle;
short fSelector=0;

void MMDisp();
void idleF();
void Options2();

void HideWindow(char* Title)
{
	HWND hwnd;
	hwnd=FindWindowA(0,Title);
	
	if(!hwnd)
		cout<<"bad handle\n";

ShowWindow(hwnd,SW_HIDE);

}
void SpF ( int k, int x, int y ) 
 {

	 switch ( k ) 
	{
  case GLUT_KEY_UP:     
	
	  fSelector--;
	  fSelector==-1?
		  fSelector=2
	  :
	  fSelector%=3;
		break;
  
  case GLUT_KEY_DOWN: 
		fSelector++;
	  fSelector==-1?
		  fSelector=2
	  :
	  fSelector%=3;


		break;
	 }
}

void LoadLDG(Level_Data2& ld)
{
	
	
		char path[200];
	GetOpenFileNameA(&GetOFN(path));


	if(FindStr(path,".ld")==-1)
	{MessageBoxA(FindWindowA(0,"Game_AI"),"Invalid file!",0,MB_OK); LoadLD(EditorLevel2,"defaultLD.ld");}
	else
	LoadLD(GameLevel2,path);
	
}

void KbF ( unsigned char key, int x, int y )
{
	switch(key)
	{
	case 13:
		Options2();
		break;
	}
}
void MainMenu()
{
	glutCreateWindow("Game_AI");
	glClearColor(0, 0, 0, 1);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0,width,height,0, 0, 1);
	 glutDisplayFunc(MMDisp);
	 glutSpecialFunc(SpF);
	 glutIdleFunc(idleF);
	 glutKeyboardFunc(KbF);
	 b1=GetBmp("h/button.bmp");
	 bh=GetBmp("h/buttonh.bmp");
	  b1t=GetBmp("h/b1t.bmp");
	  b2t=GetBmp("h/b2t.bmp");
	   b3t=GetBmp("h/b3t.bmp");
	// DrawBitmap(

}

 void Options()
 {
	 
cout<<"Game: 1\nLevel Editor: 2\n";

short op;
short secOp;
cin>>op;

void (*kb)(unsigned char, int, int);
void (*sp)( int k, int x, int y );
void (*spu)( int key, int x, int y );
void (*d)(), (*idle)();


switch(op)
{
	case 1:
		
		
		{
			LoadLevel(GameLevel);
		
			//gb= new int[(width*height*sizeof(int))];
			kb=KbGame;
			sp=SpGame;
			spu=SpuGame;
			d=DispGame;
			idle=id;
			frb.size=6;
			cout<<"Wait...";
			frb.Load("h/bg3(100).bmp");

			frb.SetDuration(0,150);
			
			//frb.SetDuration(24,30);
			//frb2.size=2;
			//frb2.Load("h/en(100).bmp");


			//CTexture.base=GetBmp("h/en(100).bmp");
			//c.tex=CTexture;
			
			gSetFB(cfrb, "h\\en2(100).bmp",1, "h\\en2(200).bmp",1,"h\\en2(300).bmp",1);
			gSetFB(efrb, "h\\en(100).bmp",1, "h\\en(200).bmp",1,"h\\en(300).bmp",1);
			GObmp=GetBmp("h/go.bmp");
			

			texture.base=GetBmp("h\\texture03.bmp");
			texture.width=1;
			texture.height=1;
			Respawn(c);
			
		}
		
//		else if(secOp==1)
//		{
//			//sd=GetSensorData(c, GameLevel);
//					
//			
//			/*b.Initialize(sd->size,8,3);
//			b.GetDesiredOutput(NULL);
//			LoadRecording(rarr, sd->size);
//			Train(b,rarr);
//			LoadRecording(rarr, sd->size);
//			Train(b,rarr);*/
//			
//			/*Brain b1, b2, b3;
//				
//			if(!brain.Load())
//				{	sd=GetSensorData(c, GameLevel);
//					brain.Initialize(sd);
//					brain.CreateBrain();
//				}*/
//			
//			
//	/*	b1.Load();
//			b2.Load();
//
//			for(int i=5; i<20; i++)
//		{b3=Offspring(b1,b2);
//			b3.Save(i);
//			}*/
//
//
//			/*kb=KbAI;
//			sp=SpGame;
//			spu=SpuGame;
//			d=DispGame;*/
////			idle=idAI;
//
//			
//			
//		}

		
	break;
	case 2:
		kb=KbLE;
		sp=SpLEP;
		spu=NULL;
		d=DispLE;
		idle=idLE;

		LoadLevel(EditorLevel);

		/*CTexture.base=GetBmp("h/en(100).bmp");
		CTexture.width=1;
		CTexture.height=5;

		
		
		LETexture.base=GetBmp("h\\texture04.bmp");*/
		break;
	default:
		return;
}
		glutCreateWindow("Game_AI");
		
		glClearColor(0, 0, 0, 0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0,width,height,0, 0, 1);
		glutKeyboardFunc(kb);
		glutSpecialFunc(sp);
		glutPassiveMotionFunc(EMousePos);
		glutMouseFunc(EMouseFunc);
		glutSpecialUpFunc(spu);
        glutDisplayFunc(d);
        glutIdleFunc(idle);
 }

 
 void Options2()
 {
	 



void (*kb)(unsigned char, int, int);
void (*sp)( int k, int x, int y );
void (*spu)( int key, int x, int y );
void (*d)(), (*idle)();

bool op2=0;

switch(fSelector)
{
	
case 2:
	op2=1;
	nLEVELS=0;

	LoadLDG(GameLevel2);
	GLoadLevel2(GameLevel2);

		case 0:
		
		
		{
			
			//LoadLevel(GameLevel);
			if(!op2)
			{LoadLD(GameLevel2,"level1.ld");
			GLoadLevel2(GameLevel2);
			}

			//gb= new int[(width*height*sizeof(int))];
			kb=KbGame;
			sp=SpGame;
			spu=SpuGame;
			d=DispGame;

			idle=id;
			frb.size=52;
			cout<<"Wait...";
			GP=GameLevel2.PlatformTexture;
			//GE=GameLe;
			GC=GameLevel2.CoinTexture;
			lBeginG=GameLevel2.lBegin;
			lEndG=GameLevel2.lEnd;
			//EnemyFB=ResolveFB(EEFB);

		gPlatformTexture=ResolveTextureId(GP);
		gEnemyTexture=ResolveTextureId(GE);
		gCoinTexture=ResolveTextureId(GC);

			frb.Load("h/bg3(100).bmp");

			frb.SetDuration(0,150);
			
			frb.SetDuration(24,30);
			//frb2.size=2;
			//frb2.Load("h/en(100).bmp");


//			CTexture.base=GetBmp("h/en(100).bmp");
			//c.tex=CTexture;
			
			gSetFB(cfrb, "h\\mc(100).bmp",4, "h\\mc(200).bmp",2,"h\\mc(200).bmp",2);
			cfrb[0].SetDuration(5);
			gSetFB(efrb, "h\\en(100).bmp",1, "h\\en(200).bmp",1,"h\\en(300).bmp",1);
			GObmp=GetBmp("h/go.bmp");
			CompleteBmp=GetBmp("h/complete.bmp");
			FinishBmp=GetBmp("h/finish.bmp");
			
			WinBmp=GetBmp("h/win.bmp");
			//texture.base=GetBmp("h\\texture03.bmp");
			//texture.width=1;
			//texture.height=1;
		
			//HideWindow(WTitle);
			Respawn(c);
		
			break;
		}
		
	case 1:
		kb=KbLE;
		sp=SpLEP;
		spu=NULL;
		d=DispLE;
		idle=idLE;

		InitLE();

		break;
	default:
		return;
}
//		glutCreateWindow("Game_AI");
		
	//	glClearColor(0, 0, 0, 0);
      //  glMatrixMode(GL_PROJECTION);
        //glLoadIdentity();
        //glOrtho(0,width,height,0, 0, 1);
		glutKeyboardFunc(kb);
		glutSpecialFunc(sp);
		glutPassiveMotionFunc(EMousePos);
		glutMouseFunc(EMouseFunc);
		glutSpecialUpFunc(spu);
        glutDisplayFunc(d);
        glutIdleFunc(idle);
 }

void MMDisp()
{

	float fx, fy;
	float shift =120;

	fx=250, fy=180;
	glClear(GL_COLOR_BUFFER_BIT);	
	
	
	fSelector==0?
	DrawBitmap(fx,fy,bh,1),
	DrawBitmap(fx,fy,b1t,1)
	:
	DrawBitmap(fx,fy,b1,1) ,
	DrawBitmap(fx,fy,b1t,1);

	fSelector==1?
		DrawBitmap(fx,fy+ shift,bh,1),
		DrawBitmap(fx,fy+ shift,b2t,1)
		:
		DrawBitmap(fx,fy+ shift,b1,1),
		DrawBitmap(fx,fy+ shift,b2t,1);
	
		fSelector==2?
		DrawBitmap(fx,fy+ shift*2,bh,1), 
		DrawBitmap(fx,fy+ shift*2,b3t,1) 
		:
		DrawBitmap(fx,fy+ shift*2,b1,1),
		DrawBitmap(fx,fy+ shift*2,b3t,1);
	
	glutSwapBuffers(); 
  


}

void idleF()
{
	glutPostRedisplay();

}