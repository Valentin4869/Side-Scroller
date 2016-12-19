#pragma once

#include "stdafx.h"
#include "Data.h"
#include "StrOps.h"



struct bmpRGB{
unsigned char R, G, B, A;


};

class Container
{
public:
    Container(bmpRGB* buf, int len);

    bmpRGB operator[] (int i) { return buffer[validIndexes[i]]; }
	
    void pushRowsBack(int n, int rowLength);
    void restore();

    int size() { return validIndexes.size(); }

	
    std::vector<bmpRGB> buffer;
    std::vector<int> validIndexes;
};
 
 Container::Container(bmpRGB* buf, int len) 
    : buffer(buf,buf+len), 
    validIndexes(len, 0)
{
	
    for (int i = 0; i < len; ++i)
    {
        validIndexes[i] = i;
    }
}

 void Container::pushRowsBack(int n, int rowLength)
{
    int numRows = validIndexes.size() / (float)rowLength + 0.5;
    std::vector<int>::iterator it = validIndexes.begin();

    // go through all the rows
    for (int i = 0; i < numRows; ++i)
    {
        // erase the first n elements in the row
        for (int j = 0; j < n; ++j)
        {
            it = validIndexes.erase(it);
        }

        // advance iterator to the next row
        it += rowLength - n; 
    }
}

 void Container::restore()
{
    validIndexes.resize(buffer.size());
    for (int i = 0; i < validIndexes.size(); ++i)
    {
        validIndexes[i] = i;
    }
}

struct Bitmap
{
	int Width, 
		Height,
		Size;

	bmpRGB *Data;

	
};

struct Bitmap2
{
	int Width, 
		Height,
		Size;

	Container *Data;
	
};




void FrameBuffer:: Load(char* Path)
	{
		char *mpath;
		mpath=NewStr(Path);
		
		
		int xi;
		frames= new Bitmap[size];
		duration =new float[size];
		track =new float[size];
		

		xi=FindStr(mpath,".bmp");
		xi-=3;
		
		for(int i=0; i<size ; i++)
		{
			
			
				mpath[xi]=48+i/10;
				mpath[xi+1]=i%10+48;


			frames[i]=*GetBmp(mpath);
		cout<<"Loaded "<<mpath<<endl;
		}
		
		Default();

		delete[] mpath;
		
	}

Bitmap* GetBmp( char* Path)
{
	
	Bitmap *Bmp;
	Bmp=new Bitmap;
	unsigned char Header[54]={0};			

	//cout<<Path<<endl;
	
	basic_ifstream<unsigned char> bitmap_file(Path, ios::in | ios::binary);
		
	
	bitmap_file.read(Header,54);
	//bitmap_file.seekg(0, ios::beg);
	//bitmap_file.seekg(ios::beg,0);
	Bmp->Size=0;
	Bmp->Width=0;
	Bmp->Height=0;
	
	for(int i=0;i<4;i++)
	{
		Bmp->Size+=(unsigned char)Header[2+i]*pow(256.0,i);
		Bmp->Width+=(unsigned char)Header[18+i]*pow(256.0,i);
		Bmp->Height+=(unsigned char)Header[22+i]*pow(256.0,i);
	}
	
	//cout<<"Size: "<<Bmp->Size<<"\n "<<Bmp->Width<<" x "<<Bmp->Height<<endl;

	

	Bmp->Data=new bmpRGB[Bmp->Size];
	unsigned char *buffer;

	buffer=new unsigned char[Bmp->Size];

	bitmap_file.read(buffer, Bmp->Size);

	/*for(int i=0; i<Bmp->Size; i++)
	{cout<<"["<<i+54<<"]= "<<(int)buffer[i]<<endl; system("pause");}*/


	for(int i=0; i<Bmp->Height*Bmp->Width; i++)
	{
		
		
			Bmp->Data[i].B=buffer[i*4];
			Bmp->Data[i].G=buffer[i*4 + 1];
			Bmp->Data[i].R=buffer[i*4 + 2];
			Bmp->Data[i].A=255-buffer[i*4 + 3];
	}


	delete[] buffer;
	bitmap_file.close();
	return Bmp;

}

void DrawBitmap(int x, int y, Bitmap* bmp)
{
	glRasterPos2f(x,y);
	glDrawPixels(bmp->Width, bmp->Height, GL_RGBA,GL_UNSIGNED_BYTE, bmp->Data);
}

void FlipFB(FrameBuffer& fb, bool dir)
{
	if(fb.facing==dir)
	{return;
	//cout<<"C: "<<fb.facing<<endl;
	
	}

	//cout<<"W: "<<fb.facing<<"---->";
	fb.facing=(fb.facing+1)%2;
	//cout<<fb.facing<<endl;

	for(int i=0; i<fb.size; i++)
		FlipBmp(&fb.frames[i]);
}

void FlipBmp(Bitmap* bmp)
{
	bmpRGB temp;
	
	for(int j=0; j<bmp->Height; j++)
	{
		
		for(int f=0, b=bmp->Width*j+bmp->Width-1; f<bmp->Width; f++, b--)
		{
		
		if(f+bmp->Width*j>=b)
			break;

			temp=bmp->Data[f+bmp->Width*j];
			bmp->Data[f+bmp->Width*j]=bmp->Data[b];
			bmp->Data[b]=temp;

		}
	}
}


void FlipTexture(Texture& t, bool dir)
{
	if(dir==t.facing)
	 return;

	t.facing= (t.facing+1)%2;
	FlipBmp(t.base);
	
}


void DrawBitmap(int x, int y, Bitmap* bmp, bool Alpha)
{
	

	if(Alpha)
	{	glRasterPos2f(x,y);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glDrawPixels(bmp->Width, bmp->Height,GL_RGBA,GL_UNSIGNED_BYTE,bmp->Data);
		glDisable(GL_BLEND);
	}
	else
		DrawBitmap(x,y,bmp);
}

void BitmapAnimation(int x, int y, FrameBuffer &fb)
{
	
//timer
	short curr=fb.current;
	//static int track=fb.duration[curr];
	
	
	if(fb.track[curr]==0)
	{
	fb.current=(++fb.current)%fb.size;
	curr=fb.current;
	fb.track[curr]=fb.duration[curr];
	
	}
	else
	fb.track[curr]--;
	
DrawBitmap(x, y, &fb.frames[curr],1);

	
}


void DrawTexture(int x, int y, Texture& tex, bool mode)
{
	
	if(mode)
	  {
		 
			Bitmap* newbitmap;
			newbitmap= new Bitmap;
			int Bsize=tex.base->Width*tex.base->Height;
			int Tsize=tex.width*tex.height;
			

			newbitmap->Data=new bmpRGB[Bsize*Tsize];
		
			newbitmap->Width=tex.base->Width*tex.width;
			newbitmap->Height=tex.base->Height*tex.height;
			newbitmap->Size=newbitmap->Width*newbitmap->Height;

				for(int j=0; j<newbitmap->Height; j++)
				{
				
					for(int w=0; w<newbitmap->Width; w++)
					{
						newbitmap->Data[j*newbitmap->Width + w]= tex.base->Data[(j%tex.base->Height)*(tex.base->Width)+ w%tex.base->Width];
					}
		
				}		
		
	
														/*for(int i=0; i<newbitmap->Size; i++)
		{
			cout<<"R: "<<newbitmap->Data[i].R<<", R: "<<tex.base->Data[i].R<<endl;
			cout<<"B: "<<newbitmap->Data[i].B<<", B: "<<tex.base->Data[i].B<<endl;
			cout<<"G: "<<newbitmap->Data[i].G<<", G: "<<tex.base->Data[i].G<<endl<<"---\n";
		}*/

			DrawBitmap(x ,y + newbitmap->Height-1*tex.base->Height, newbitmap,1);

			delete[] newbitmap->Data;
			delete newbitmap;
		}
	else
	{
		
			for(int i=0; i<tex.height; i++)
			{
		
				for(int jj=0; jj<tex.width;  jj++)
				{
					
					DrawBitmap(x + jj*tex.base->Width ,y + i*tex.base->Height ,tex.base,1);
					
				}
			}

	}

	
}

void Character::Draw()
{	
			
	//cout<<"Centre "<<centre.x<<endl;


	//DrawBitmap(centre.x-tex.base->Width/2, centre.y +tex.base->Height/2 ,tex.base,1);
	//cout<<iFB<<endl;
	//BitmapAnimation(centre.x-tex.base->Width/2, centre.y +tex.base->Height/2,fb[iFB]);
	/*DrawCPoints();
	
	glColor3f(color.R,color.G,color.B);
	glBegin(GL_POLYGON);
	
	for(int i=0; i<sides; i++)
	glVertex2f(length*cos((i*(360.0/sides)-45)/180.0*PI)+centre.x, length*sin((i*(360.0/sides)-45)/180.0*PI)+centre.y);

	
	glEnd();*/

}


//void DrawTexture(int x, int y, Texture& tex)
//{
//
//	
//
//
//}