#pragma once
#include "stdafx.h"


//
//struct Node{
//
//	//float value;
//	
//
//};
//
//
//struct Effector: Node{
//	double Sigmoid(double v)
//{
//	return 1.0/(1.0+pow(2.7183,-1*v/0.5));
//
//}
//	float value;
//	void Get(float v)
//		{
//			
//			value+=v; 
//			value/=1000;
//		}
//};
//
//struct Neuron_2: Node{
//
//	float value;
//	short fid;
//
//	short Ncon;
//	int *Nout;
//	Neuron_2* n;
//
//	short Econ;
//	int* out;
//	Effector* e;
//
//	double* w;
//	float weight;
//	float threshold;
//
//	
//	void (**operation)(Neuron_2*);
//
//	
//	void Process()
//	{		
//		
//		(operation[fid])(this);
//		
//	}
//
//void Get(float v){
//value+=v;	
//}
//
//void Send(){
//
//	
//		if(value>=threshold)
//		
//		{
//				
//		for(int i=0; i<Ncon; i++)
//				{
//				//cout<<"Sending NN "<<value<<endl;
//				n[Nout[i]].Get(value);
//				}	
//				
//				for(int i=0; i<Econ; i++)
//				{//cout<<"Sending NE "<<value<<endl;
//					
//				e[out[i]].Get(value);
//				}	
//		}
//				value=0;
//}		
//		
//		   
//};
//
//
//struct Sensor: Node{
//	float value;
//	
//	int conn;
//	double * w;
//	Neuron_2 *n;
//	int Econ;
//	Effector *e;
//
//	int *out;
//	int *Eout;
//
//	
//	void Send(){
//		
//		
//		for(int i=0; i<conn; i++)
//		{
//			
//
//			n[out[i]].Get(value*w[i]);
//			
//		}
//
//		/*for(int i=0; i<Econ; i++)
//		{e[Eout[i]].Get(value);}*/
//
//		value=0;
//		}
//
//};
//
//struct SensorData{
//
//	double* data;
//	int size;
//
//};

enum Texture_Id{t_00, t_10, t_20, t_30, e_00, e_10, e_20, c_00, c_10, c_20};
enum FB_Id{fb_01, fb_02, fb_03, fb_04};
enum Bg_Id{bg_01, bg_02, bg_03, bg_04};
struct bmpRGB;
struct Bitmap;
struct FrameBuffer;
struct Texture;
Bitmap* GetBmp(char*);
void DrawBitmap(int, int, Bitmap*);
void BitmapAnimation(int, int , FrameBuffer&);
void FlipTexture(Texture& t, bool dir);
void FlipBmp(Bitmap*);
void FlipFB(FrameBuffer& fb, bool dir);
OPENFILENAMEA GetOFN(char* filep);
Texture ResolveTextureId(Texture_Id);
FrameBuffer* ResolveFB(FB_Id);


struct Texture{
	Bitmap* base;
	bool facing;
	int width, height; //Number of copies
	Texture():facing(0), width(1), height(1){}
	//~Texture(){delete[] base;}
	
};


struct FrameBuffer{
	Bitmap *frames;
	float *duration, *track;
	int size;
	int current;
	bool facing;
	void Load(char* Path);
	

	void Default()
	{
		for(int i=0; i<size; i++)
			duration[i]=track[i]=2;
	}
	 void SetDuration( int d)
	 {
		 for(int i=0; i<size; i++)
			duration[i]=track[i]=d;
	 }
	 void SetDuration(short i, int d)
	 {
		 duration[i]=d;

	 }

	 ~FrameBuffer(){delete[] frames, delete[] duration, delete[] track;}

	FrameBuffer():current(0), facing(0){ }

};





struct Vector2d{

	float x, y;

	Vector2d(){zero();}
	void zero(){x=0; y=0;}
};


struct RGBC{

	float R;
	float G;
	float B;

	void operator=(RGBC col){R=col.R;B=col.B;G=col.G;}
};

struct Velocity
{
	double U,R,D,L;
	Velocity(){U=0;R=0;D=0;L=0;};
	Velocity(double g){U=0;R=0;D=g;L=0;}

	void cancel(direction dir){
	switch(dir)
	{
	case RIGHT:
		R=0;
		
		break;
	case LEFT:
		L=0;
		
		break;
	case UP:
		U=0;
		
		break;
	case DOWN:
		D=0;
		
		break;
	}
	
		}

	
	
		
};

struct Timer{

	double start,end;
	bool state;
	float rate;
	double get(){end=clock()-start; return (end*rate/(double)(CLOCKS_PER_SEC));}
	void stop(){state=0;}
	void begin(){if(!state) {start=clock(); state=true;}} //begin/continue

	Timer(){rate=1; state=0;}
};


struct Point2d{
	float x,y;

	void operator=(Point2d p2){x=p2.x; y=p2.y;}
};



