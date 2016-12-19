#pragma once

#include"stdafx.h"
#include "Data.h"
#include "Button_1.h"
#include"Character.h"
#include"Platform.h"
#include "Level_Editor.h"
#include "BmpOps.h"

Bitmap *bmp;
Bitmap *GObmp, *FinishBmp, *CompleteBmp, *WinBmp;
Bitmap2 *bmp2;
FrameBuffer frb;
FrameBuffer cfrb[3];
FrameBuffer efrb[3];
short nLEVELS=3;
time_t respawnt;

short Progress=0;

 char level[]="Level 0";
 char Lives[]="Lives: 0";
 char Time[]="Time: 000";
 char Coins[]="Collected 000";

int nScore=0, nLives=3, nTime=150, nLevel=0;
float width= 800.0;
float height= 600.0;
 const double sizess=width*height;
int score=0;
 double t01, t02;
 Timer frames;
 short fps=60;

  
	Texture texture;

 Level_Data GameLevel;

  
 double s, ee;
 bool keydown=false;
 Character c;
 float GamexBegin=0, GamexEnd=0;
time_t tim;
//SensorData* sd;
Enemy eTemp;
Coin cTemp;
Platform pTemp;
vector<Enemy> enm(5,eTemp);
vector<Coin> coin(5,cTemp);
//Enemy enm[5];
float Ag=0;
float Bg=width;
int TestPoint=0;
float gcentre=(Ag+(Bg-Ag)/2);
	float t1=c.centre.x-gcentre;
//----------------------------------------------------
Level_Data2 GameLevel2;
Texture_Id GE, GP, GC, GB;
FB_Id GEFB;
Texture gEnemyTexture, gPlatformTexture, gCoinTexture, gBackgroundTexture;
vector<Platform>GPlatforms(0);
vector<Enemy>GEnemies(0);
vector<Coin> GCoins(0);
float lBeginG, lEndG;
	
		void GLoadLevel2(Level_Data2);
	 void KbGO ( unsigned char key, int x, int y ) ;
	 void SpGame ( int k, int x, int y );
	 bool CollectCoin(int);
	 bool EnemyContact();
//struct RecordData{
//	SensorData* rsd;
//
//bool cr,cl,cj;
//};
//
//vector<RecordData> rarr;
//
//RecordData RecordFrame(Character&,Level_Data&);

//GLuint LoadTexture( const char * filename )
//{
//
//  GLuint texture;
//
//  int width, height;
//
//  unsigned char * data;
//
//  FILE * file;
//
//  file = fopen( filename, "rb" );
//
//  if ( file == NULL ) return 0;
//  width = 1024;
//  height = 512;
//  data = (unsigned char *)malloc( width * height * 3 );
//  //int size = fseek(file,);
//  fread( data, width * height * 3, 1, file );
//  fclose( file );
//
// for(int i = 0; i < width * height ; ++i)
//{
//   int index = i*3;
//   unsigned char B,R;
//   B = data[index];
//   R = data[index+2];
//
//   data[index] = R;
//   data[index+2] = B;
//
//}

//
//glGenTextures( 1, &texture );
//glBindTexture( GL_TEXTURE_2D, texture );
//glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
//glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
//
//
//glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
//glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
//glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
//gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
//free( data );
//
//return texture;
//}


//void SaveRecording(vector<RecordData> recd, char* path)
//{
//	ofstream outfile(path, ios::binary|ios::out|ios::app);
//	int size=recd.size();
//
//	outfile.write(reinterpret_cast<char*>(&size),sizeof(int));
//
//	//For every element in vector
//	for(int i=0; i<recd.size(); i++)
//	{
//		//for each record.sd
//		for(int j=0; j<recd[i].rsd->size; j++)
//		{
//			//write each element in sd to file
//			outfile.write(reinterpret_cast<char*>(&recd[i].rsd->data[j]),sizeof(double));
//
//		}
//
//		//write corresponding output/controllers
//		outfile.write(reinterpret_cast<char*>(&recd[i].cj),sizeof(bool));
//		outfile.write(reinterpret_cast<char*>(&recd[i].cr),sizeof(bool));
//		outfile.write(reinterpret_cast<char*>(&recd[i].cl),sizeof(bool));
//	}
//
//}
//void LoadRecording(vector<RecordData> &recd, char *path, int size)
//{
//
//	recd.clear();
//	RecordData trd;
//	trd.rsd=new SensorData;
//	trd.rsd->size=size;
//	trd.rsd->data=new double[trd.rsd->size];
//
//	int recsize;
//	ifstream infile(path, ios::binary|ios::in);
//	
//	infile.read(reinterpret_cast<char*>(&recsize),sizeof(int));
//	//For every element in vector
//	for(int i=0; i<recsize; i++)
//	{
//		//for each record.sd
//		for(int j=0; j<size; j++)
//		{
//			//write each element in sd to file
//			infile.read(reinterpret_cast<char*>(&trd.rsd->data[j]),sizeof(double));
//
//		}
//		
//		//write corresponding output/controllers
//		infile.read(reinterpret_cast<char*>(&trd.cj),sizeof(bool));
//		infile.read(reinterpret_cast<char*>(&trd.cr),sizeof(bool));
//		infile.read(reinterpret_cast<char*>(&trd.cl),sizeof(bool));
//
//		recd.push_back(trd);
//	}
//
//	cout<<"Size load: "<<recd.size()<<endl;
//	//system("pause");
//}
//
//void LoadRecording(vector<RecordData> &recd, int size)
//{
//char *path;
//	path=new char[25];
//	cout<<"Enter load path: ";
//	cin>>path;
//
//	LoadRecording(recd,path, size);
//	
//	delete[] path;
//
//}
//
//void SaveRecording(vector<RecordData> recd)
//{
//	char *path;
//	path=new char[25];
//	cout<<"Enter save path: ";
//	cin>>path;
//
//	SaveRecording(recd,path);
//	
//	delete[] path;
//}
//
//
// 
// void ApplyEffectors(Effector* ef, Character c0)
// {
//	 
//	float th=8.0;
//	float th2=20.0;
//	
//	  	 if(ef[0].value>=th && ef[0].value<=th2)
//		  c.Jump();
//
//	  if(ef[1].value>=th && ef[1].value<=th2)
//		  c.right=true;
//	   else
//		   c.right=false;
//
//		
//	    if(ef[2].value>=th && ef[2].value<=th2)
//		  c.left=true;
//	   else
//		   c.left=false;
//
// for(int i=0; i<3; i++)
// {
//	 cout<<"Effector "<<i<<": "<<ef[i].value<<endl; 
//	
//	ef[i].value=0;
// 
// }
//
// //system("pause");
// }
//

void GLoadLevel2(Level_Data2 ld)
{
	GPlatforms.clear();
	GCoins.clear();
	GEnemies.clear();
	
	for(int i=0; i<ld.nP; i++)
	{
		
		pTemp.start=ld.pStart[i];
		pTemp.height=ld.pHeight[i];
		pTemp.width=ld.pWidth[i];
		GPlatforms.push_back(pTemp);
	}

	for(int i=0; i<ld.nC; i++)
	{
		cTemp.centre=ld.cCentre[i];
		GCoins.push_back(cTemp);
	}

	for(int i=0; i<ld.nE; i++)
	{
		eTemp.centre=ld.eCentre[i];
		GEnemies.push_back(eTemp);
	}

	nLevel=ld.LevelId;
	
}

void gSetFB(FrameBuffer* fb, char* pM, int sM, char* pJ, int sJ, char* pF, int sF)
	{
		fb[0].size=sM;
		fb[0].Load(pM);

		fb[1].size=sJ;
		fb[1].Load(pJ);

		fb[2].size=sF;
		fb[2].Load(pF);
	}

void gSetFB(FrameBuffer* fb, char* p, int s)
	{
		
		for(int i=0; i<3; i++)
		{
			fb[i].size=s;
			fb[i].Load(p);
		}
}

bool Contact(Point2d point,Platform p, float l)
{
	
	bool x=false, y=false;
	//check x
	if(point.x+l>= p.start.x && (point.x-l)<= (p.start.x+p.width))
		x=true;

	if(point.y+l>= p.start.y && (point.y-l)<= (p.start.y+p.height))
		y=true;
	
		return(x && y);
}

void Respawn(Character &ch)
{
	respawnt=clock();
	ch.centre.x=lBeginG;
	ch.centre.y=100;
	ch.velocity.cancel(DOWN);
	ch.velocity.cancel(UP);
	ch.Update();
}

void Contact_Test(Character &c, vector<Platform>& Platforms)
{
		bool br=false;
		

		c.contact=false;
		c.PlatformsContact=0;
		c.GroundContact=false;

		for(int i=0;i<(int)Platforms.size();i++)
	{

		if(Platforms[i].start.x<=Bg && Platforms[i].start.x+Platforms[i].width>=Ag)
		{		
				if(Contact(c.centre,Platforms[i], c.length))
				{
					
				c.contact=true;
				
				//Determine contact point
				for(int ii=0; ii<4; ii++)
					{
						if(Contact(c.cpoints[ii], Platforms[i], 0.0))
						{
							c.PlatformsContact++;
							c.p=&Platforms[i];
				
							if(ii==DOWN)
								c.GroundContact=true;

							c.velocity.cancel((direction)ii);
							c.Reposition((direction)ii);

						}
					}

				}
	
		}
	
	}



}


	
	



//SensorData* GetSensorData(Character& c0, Level_Data& d0)
//{
//	SensorData* sd;
//	sd= new SensorData;
//	short nPlatforms=d0.nPlatforms;
//	sd->size=9+nPlatforms*4;
//	//sd->size=7;
//	sd->data=new double[sd->size];
//
//	sd->data[0]=c0.velocity.D;
//	sd->data[1]=c0.velocity.U;
//
//	sd->data[2]=c0.GroundContact*1000;
//	sd->data[3]=c0.contact*1000;
//	sd->data[4]=c0.jumping*1000;
//
//	sd->data[5]=d0.xBegin;
//	sd->data[6]=d0.xEnd;
//	sd->data[5]=c0.centre.x;
//	sd->data[6]=c0.centre.y;
//	sd->data[7]=c0.velocity.L;
//	sd->data[8]=c0.velocity.R;
//
//	for(int i=0; i<nPlatforms*4; i+=4)
//	{
//		sd->data[9+i]=d0.pd[i/4].height;
//		sd->data[9+i+1]=d0.pd[i/4].width;
//		sd->data[9+i+2]=d0.pd[i/4].start.x;
//		sd->data[9+i+3]=d0.pd[i/4].start.y;
//	}
//	
//	
//	return sd;
//}

//void Initialize(Sensor *s, Neuron_2 *n, Effector *e, int ssize, int nsize, int esize)
//{
//	//Sensors
//	for(int i=0; i<ssize; i++)
//	{
//		s[i].conn=0;
//		s[i].out=n;
//		s[i].value=0;
//	}
//
//	OpFunc* opfunc=GetFunctionArray();
//
//
//	//Neurons
//	for(int i=0; i<nsize; i++)
//	{
//		n[i].value=0;
//		n[i].Econ=0;
//		n[i].Ncon=0;
//		n[i].operation=opfunc[rand()%NumOp];
//		n[i].weight=(float)(rand()%10/10.0);
//		n[i].threshold=(float)(rand()%100/100.0);
//	}
//
//	//Effectors
//	for(int i=0; i<esize; i++)
//	{
//		e[i].value=0;
//	}
//}
//
//void CreateBrain(Sensor* s, Neuron_2* n, Effector* e, SensorData* sd)
//{
//  
//const short NeuronCon=10;//Number of sensor to neuron connections
//const short ECon=2;	//Number of Neuron to Effector connections
//const short NNC=5;
//const short ECon2=1;
//
//Neuron_2 **Ntemp;
//Effector **Etemp;
//
//  for(int i=0; i<sd->size; i++)
//  {
//	 /* cout<<"Moving "<<i<<" " <<sd->data[i]<<endl;*/
//	  s[i].value=(float)(sd->data[i]/1000.0);
//	  s[i].conn=NeuronCon;
//	  s[i].Econ=ECon2;
//
//	  //Connect each sensor to 'NeuronCon' random neurons
//	  
//	  Ntemp=new Neuron_2*[NeuronCon];
//	   Etemp=new Effector*[ECon2];
//
//	  for(int i2=0; i2<NeuronCon; i2++)
//			{
//				
//				Ntemp[i2]=&n[rand()%NumN];
//				
//			}
//
//	   for(int i2=0; i2<ECon2; i2++)
//			{
//				
//				Etemp[i2]=&e[rand()%3];
//				
//			}
//
//	  s[i].out=*Ntemp;
//	  s[i].Eout=*Etemp;
//	
//  }
//
//  //Each neuron connects to random effectors
//    Ntemp=new Neuron_2*[NeuronCon];
//	  for(int i=0; i<NumN; i++)
//	  {
//		  
//		  n[i].Econ=ECon;
//		  n[i].Ncon=NNC;
//		  //Connect to random effectors
//		 
//		  Etemp=new Effector*[ECon];
//		  Ntemp=new Neuron_2*[NNC];
//
//		   for(int i2=0; i2<ECon; i2++)
//				{		
//					Etemp[i2]=&e[rand()%3];					
//				}
//		
//		    for(int i2=0; i2<NNC; i2++)
//				{		
//					Ntemp[i2]=&n[rand()%NumN];					
//				}
//		
//		  
//		   n[i].out=*Etemp;
//		   n[i].Nout=*Ntemp;
//		 
//	  }
//}

void MoveScene(bool ShowPoints)
{

	gcentre=(Ag+(Bg-Ag)/2);
	t1=c.centre.x-gcentre;
		
		
	
		
	
		glTranslatef(-t1,0,0);
		Ag+=t1; Bg+=t1;
	
	

		/*cout<<"A: "<<A<<", B: "<<B<<endl;
		cout<<"Centre: "<<c.centre.x<<", calc: "<<(A+(B-A)/2)<<endl;*/

		if(ShowPoints)
		{
		glBegin(GL_POINTS);

			glColor3f(1,0,0);
			glVertex2f(Ag+2,340);

			glColor3f(0,1,0);
			glVertex2f(Bg-2,340);

			glColor3f(0,0,1);
			glVertex2f(Ag+(Bg-Ag)/2,340);
		
		glEnd();
		
		
		}

}
 
bool DeathTest(Character &ch)
{

	if(ch.dead)
		return true;

	
if((EnemyContact() || ch.centre.y>=850) && nTime>0)
	{	
		if(ch.Life>0)
		{
			ch.Life--;
			//cout<<ch.Life<<" lives remaining.\n";
			score-=100;
			score<0?
				score=0: 0;

			Respawn(ch);
			return false;
		}

			else
			 {
				 //if(!c.dead)
				 //{
					// c.dead=true;
					////Restart game
					//cout<<"Died.\n";
					//score-=100;
					//
				 //}
				 
				 return true;
				//ch.Life=3;
			
			 }	
		
		
	}

return false;
}

bool EndReached()
{
	if(c.centre.x>=lEndG)
	{
		
		//Stop game
		return true;
		//cout<<"Score: "<<0<<endl;

	}

	return false;
}


void id()
 {
	
	 static time_t tStart=clock();
	
	 if(clock()-tStart>=CLOCKS_PER_SEC && tStart>0)
		 nTime--, tStart=clock();

	
	
	
	
	//Finished level?
	EndReached();
	
	 glutPostRedisplay();
 }



void ScPrt(char* str)
 {
	 
	 glClear(GL_COLOR_BUFFER_BIT);	

		
	
	
	 for(int i=0; i<short(strlen(str));i++)
		{
		glColor3f(1,0,0);
		glRasterPos2f(350+(GLfloat)i*8,40);
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str[i]);
		}


	
}



//run at every frame to record sensordata and its corresponding output/controller value
//RecordData RecordFrame(Character& c0, Level_Data& d0)
//{
//	RecordData rd;
//
//	rd.rsd=GetSensorData(c0,d0);
//	rd.cj=c0.jumping;
//	rd.cr=c0.right;
//	rd.cl=c0.left;
//
//	return rd;
//}

//void Train(NN& nb, vector<RecordData> rd)
//{
//	double o[3];
//
//	for(int i=0; i<rd.size(); i++)
//	{
//		
//		for(int j=0; j<2; j++)
//			
//			{
//				nb.GetInput(rd[i].rsd->data);
//
//				o[0]=rd[i].cj;
//				o[1]=rd[i].cr;
//				o[2]=rd[i].cl;
//
//				for(int ii=0; ii<3; ii++)
//				{if(o[ii])o[ii]=0.55;}
//
//				nb.GetDesiredOutput(o);
//				nb.Process();
//				nb.BP();
//			}
//	}
//
//}
//
//void idAI()
//{
//
//	
//
//
//	s=clock();
//	ee=0;
//	
//
//t01=clock();
//	//Test for contact
//	
//	Contact_Test(c, GameLevel.pd);
//	
//	
//  sd=GetSensorData(c, GameLevel);
// /* for(int i=0; i<sd->size; i++)
//	  cout<<"i: "<<sd->data[i]<<endl;*/
//  //double* pp;
//
//	//pp=new double[sizess];
////glReadPixels(0,0,width,height,GL_RGB,GL_BYTE,pp);
//
//  //b.GetDesiredOutput(NULL);\
//  b.GetInput(sd->data);\
//	b.Process();
//  
//  
//  //for(int j=0; j<sd->size; j++)
//		//		{
//		//			
//		//			bpb->setInput(sd->data[j],j);
//		//			
//		//		
//		//		}
//
//  
////bpb->run();
////	delete[] pp;
//	/*if(b.output.n[0].out>=0.45 && b.output.n[0].out<=0.80)
//		c.Jump();
//
//	if(b.output.n[1].out>=0.45 && b.output.n[1].out<=0.80)
//		c.right=true;
//	else
//		c.right=false;
//
//	if(b.output.n[2].out>=0.45 && b.output.n[2].out<=0.80)
//		c.left=true;
//	else
//		c.left=false;*/
//	/*for(int i=0; i<3; i++)
//		cout<<"Output "<<i<<": "<<bpb->getOutput(i)<<endl;
//
//	double low=0.045, high=0.080;
//if(bpb->getOutput(0)>=low && bpb->getOutput(0)<=high)
//		c.Jump();
//
//	if(bpb->getOutput(1)>=low && bpb->getOutput(1)<=high)
//		c.right=true;
//	else
//		c.right=false;
//
//	if(bpb->getOutput(2)>=low && bpb->getOutput(2)<=high)
//		c.left=true;
//	else
//		c.left=false;*/
//
//	
//	/*Sensor *ss;
//  Neuron_2 *n;
//  Effector *ee;
//  */
//
// 
//
//
// // brain.ReceiveSensorInfo(sd);
//
//  
//  /*
//	ss=new Sensor[sd->size];
//	n=new Neuron_2[NumN];
//	ee=new Effector[3];
//	
//Initialize(ss,n,ee,sd->size,NumN,3);*/
//
//
////CreateBrain(ss,n,ee,sd);
//	
//	
////for(int i=0; i<sd->size; i++)
////	  ss[i].Send();
////
////
////	  for(int i=0; i<NumN; i++)
////	  {
////		  n[i].Process();
////		 //   cout<<i<<": t "<<n[i].value<<", w "<<n[i].weight<<endl;
////		  n[i].Send();
////	  
////	
////	  }
//	 // system("pause");
//  
// //Dead?
//	DeathTest(c);
//	
//	//Finished level?
//	EndReached();
//	c.Update();
//	
//	
// // brain.Process();
// 
//  //ApplyEffectors(brain.e,c);
//
//  //brain.Randomize();
//  
//		//for(int i=0; i<NumN; i++)
//		//	n[i].weight+=2.5;
//
//
//	
//	
//	
//
//	//Wait
//	while(ee<1.0/60.0){ee=clock()-s; ee/=(double)CLOCKS_PER_SEC;}	
//	 glutPostRedisplay();
//
//	 delete[] sd->data;
//	 delete sd;
//}




void PrtSc()
{
	// glClear(GL_COLOR_BUFFER_BIT);	

		
	glColor3f(1,0.2,0);
	
	
	level[6]=48+Progress+1;
	 for(int i=0; i<short(strlen(level));i++)
		{
		//glColor3f(1,0,0);
		glRasterPos2f(Ag+400+ (GLfloat)i*8,40);
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level[i]);
		}
	
	 Lives[7]=48+c.Life;
	  for(int i=0; i<short(strlen(Lives));i++)
		{
		//glColor3f(1,0,0);
		glRasterPos2f(Ag+50+ (GLfloat)i*8,40);
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, Lives[i]);
		}

glColor3f(1,1,1);

int temp=nTime;
short cpos=8;

while(temp>0)
	{
		Time[cpos]=48+temp%10;
		temp/=10;
		cpos--;
	}
	  for(int i=0; i<short(strlen(Time));i++)
		{
		
		glRasterPos2f(Ag+15+ (GLfloat)i*14,585);
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, Time[i]);
		}

	  char lf[]="Score 00000!";
		 cpos=10;
		 temp=score;
	while(temp>0)
		{
			lf[cpos]=48+temp%10;
			temp/=10;
			cpos--;
		}

		
		 for(int i=0; i<short(strlen(lf));i++)
		{
		//glColor3f(1,0,0);
		glRasterPos2f(Ag+500+ (GLfloat)i*8,40);
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, lf[i]);
		}
}



void DispGame()
{
	
	
	
	glClear(GL_COLOR_BUFFER_BIT);	
	
	t01=clock();

		
		
		{
	//Background
	
	BitmapAnimation(Ag+1,height,frb);
	
	
	 Contact_Test(c, GPlatforms);

	
	 for(int i=0; i<GEnemies.size(); i++)
	{
		if(GEnemies[i].centre.x-GEnemies[i].length<Bg && GEnemies[i].centre.x+GEnemies[i].length>Ag)
			{
				GEnemies[i].visible=true;
				Contact_Test(GEnemies[i],GPlatforms);
				GEnemies[i].TakeDecision(0);
				
				if(GEnemies[i].centre.y>800)
					Respawn(GEnemies[i]);
				GEnemies[i].Update();
			}
			else
				GEnemies[i].visible=false;
	
	}
	
	 if(!c.dead)
	c.Update();

	
	MoveScene(0);
 
	for(int i=0; i<GEnemies.size(); i++)
	{
		if(GEnemies[i].visible)
		{
			FlipFB(efrb[GEnemies[i].iFB],GEnemies[i].facing);
			BitmapAnimation(GEnemies[i].centre.x - efrb[GEnemies[i].iFB].frames[0].Width/2,
			GEnemies[i].centre.y +efrb[GEnemies[i].iFB].frames[0].Height/2,
			efrb[GEnemies[i].iFB]);
		}	
	}

	//cout<<"c: "<<c.centre.x<<", "<<lEndG<<endl;
	DrawBitmap(lEndG,GPlatforms[GPlatforms.size()-1].start.y,FinishBmp,1);

FlipFB(cfrb[c.iFB],c.facing);
	
	for(int i=0; i<GPlatforms.size(); i++)
	 {
		 GPlatforms[i].Update();
		  gPlatformTexture.height=GPlatforms[i].height/gPlatformTexture.base->Height+1;
		gPlatformTexture.width=GPlatforms[i].width/gPlatformTexture.base->Width+1;
		 DrawTexture(GPlatforms[i].start.x,GPlatforms[i].start.y + gPlatformTexture.base->Height, gPlatformTexture,0);
	 } 

	for(int i=0; i<GCoins.size(); i++)
	{
		if(GCoins[i].centre.x>=Ag && GCoins[i].centre.x<=Bg )
		{
			if(CollectCoin(i)) continue;
			DrawTexture(GCoins[i].centre.x-gCoinTexture.base->Width/2, GCoins[i].centre.y+gCoinTexture.base->Height/2, gCoinTexture,0);
		}
	}
	
	BitmapAnimation(c.centre.x - cfrb[c.iFB].frames[0].Width/2, c.centre.y +cfrb[c.iFB].frames[0].Height/2-3,cfrb[c.iFB]);

	if(!c.dead)
	c.dead=DeathTest(c);

	if( c.dead)
	{
		glutSpecialFunc(NULL);
		DrawBitmap(Ag+200,450,GObmp,0);	
	}


		}

		if(EndReached())
	{
		
		if(Progress>=nLEVELS)
		{DrawBitmap(Ag+180,420,WinBmp,0);glutIdleFunc(NULL);cout<<"Win\n"; glutKeyboardFunc(NULL); }
		
		else if(Progress<1)
		{
		DrawBitmap(Ag+220,420,CompleteBmp,0);	
		score+=nTime*2;

		//PrtSc();
		cout<<"Progress: "<<Progress<<endl;
		glutIdleFunc(NULL);
		
		//score=0;
		c.Life=3;
		}
	}
		PrtSc();
	glutSwapBuffers(); 
     
	t02=clock();
	
}


  void KbGame ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	char nextlevel[]="level2.ld";

  switch ( key ) 
	{

  case 'h':

	  break;
  case 'c':
	  if(EndReached())
			{GPlatforms.clear();
				GCoins.clear();
				GEnemies.clear();
				//glutSpecialFunc(NULL);
				Progress++;

				nextlevel[5]=Progress+1+48;
				cout<<nextlevel<<endl;
				LoadLD(GameLevel2,nextlevel);
				GLoadLevel2(GameLevel2);
				Respawn(c);
		GP=GameLevel2.PlatformTexture;
			//GE=GameLe;
			GC=GameLevel2.CoinTexture;
			lBeginG=GameLevel2.lBegin;
			lEndG=GameLevel2.lEnd;
			//EnemyFB=ResolveFB(EEFB);

		gPlatformTexture=ResolveTextureId(GP);
		gEnemyTexture=ResolveTextureId(GE);
		gCoinTexture=ResolveTextureId(GC);
				lBeginG=GameLevel2.lBegin;
				lEndG=GameLevel2.lEnd;

				glutIdleFunc(id);
	  }
	  break;
	 case 'r':
		 if(c.dead)
	  c.centre.y=0, c.dead=false, nTime=160, Respawn(c), c.Life=3, glutSpecialFunc(SpGame);
	  break;
	case 'l':
LoadLevel(GameLevel);
	 break;
    default:  
      break;
	}

}


//  
//  void KbAI( unsigned char key, int x, int y )  // Create Keyboard Function
//{
//	
//  switch ( key ) 
//	{
// //
//	case 'r':
////		b.Randomize();
//		break;
//	case 'l':
//		LoadRecording(rarr,sd->size);
//		break;
//	//case 'l':
//	//	brain.Load();
//	//	break;
//	//case 'n':
//	//	brain.Mutate();
//	//	break;
//	//case 'm':
//	//{	Brain b1, b2;
//	//		b1.Load();
//	//		b2.Load();
//	//		brain=Offspring(b1,b2);
//	//}
//	//	break;
//	//case 's':
//	//	brain.Save();
//	// break;
//    default:  
//     break;
//  }
//
//}
 void SpGame ( int k, int x, int y ) 
 {

	 switch ( k ) 
	{
  case GLUT_KEY_UP:     
	
	  c.Jump();
		break;
  
  case GLUT_KEY_DOWN: 
		
		break;

  case GLUT_KEY_RIGHT:    
	  c.right=true;
	 
		break;
	
	case GLUT_KEY_LEFT: 
		c.left=true;
		break;
	}
 }

 void SpuGame( int key, int x, int y )
 {
	
	switch ( key ) 
	{
	 case GLUT_KEY_UP:     
	
		break;
  
  case GLUT_KEY_DOWN: 
		
		break;

  case GLUT_KEY_RIGHT:    
	  c.right=false;
		break;
	
	case GLUT_KEY_LEFT: 
		c.left=false;
		break;
    
	}
	 
 }

 bool CollectCoin(int iCoin)
 {

	 if(
		 (GCoins[iCoin].centre.x<=c.centre.x+c.length && GCoins[iCoin].centre.x>=c.centre.x-c.length)
		&&
		 (GCoins[iCoin].centre.y>=c.centre.y-c.length && GCoins[iCoin].centre.y<=c.centre.y+c.length)
	  )
		{GCoins.erase(GCoins.begin()+iCoin); score+=10; return true;}

	 return false;

 }

 bool EnemyContact()
 {
	 if((clock() - respawnt)/CLOCKS_PER_SEC <1)
		return false;
	 
	 for(int i=0; i<GEnemies.size(); i++)
	 {
		 if(GEnemies[i].visible)
		 {
			 if(
				 (GEnemies[i].centre.x<=c.centre.x+c.length && GEnemies[i].centre.x>=c.centre.x-c.length)
				&&
				 (GEnemies[i].centre.y>=c.centre.y-c.length && GEnemies[i].centre.y<=c.centre.y+c.length)
			  )
			  return true;
		 }
	 }
		 return false;
	

 }

//  void MousePos(int x, int y)
//{
//	if(
//		 (x + A)<= (bbutton.start.x + bbutton.width) && (x + A)>= (bbutton.start.x)
//		&&
//		 (y)<= (bbutton.start.y + bbutton.height) && (y)>= (bbutton.start.y)
//	  )	
//	bbutton.MouseHovering=true;
//	
//	else
//		bbutton.MouseHovering=false;
//
//}
//
//
// void MouseFunc(int button, int state,int x, int y)
// {
//	 if(bbutton.MouseHovering)
//	 {
//		 if(state==GLUT_DOWN && button==GLUT_LEFT_BUTTON)
//			 bbutton.Clicked=true;
//		 else
//			 bbutton[].Clicked=false;
//	 }
//
// }
  void f(int value){}