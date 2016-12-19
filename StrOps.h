#pragma once

#include "stdafx.h"

const int l=200;	//default length
int FindLength(char* str, char ch);
int FindLength(char* str);

void NtoC(int num)
{
	char temp[]="0000000000";
	short cpos=9;

	while(num>0)
	{
		temp[cpos]=48+num%10;
		cout<<temp<<endl;
		num/=10;
		cpos--;
	}

	

}

char* NewStr(char* oldstr)
{
	char *NEWSTR;
	int size=strlen(oldstr)+1;
	NEWSTR=new char[size];
		
		for(int i=0; i<size; i++)
			NEWSTR[i]=oldstr[i];

		//NEWSTR[strlen(path)]='\0';
		return NEWSTR;
}

int FindChar(char* str, int size, char ch)
{//first occurence of ch
	int INDEX;
	for(int i=0; i<size; i++)
	{
		if(str[i]==ch)
			return i;
	}
	return -1;
}

bool CompareStr(char* str1, char* str2)
{
	//cout<<"Comparing Str1:"<<str1<<", Str2: "<<str2<<endl;
	if(strlen(str1)==strlen(str2))
	{//cout<<"Str1: "<<strlen(str1)<<", Str2: "<<strlen(str2)<<endl;
		for(int i=0; i<strlen(str1); i++)
		{
			if(str1[i]!=str2[i])
				{//cout<<"Strings not equal at "<<i<<endl; 
			
					return false;}

		}
		cout<<str1<<" = "<<str2<<endl;
		return true;
	}
	//cout<<"Strings not equal in length\n Str1: "<<str1<<", Str2: "<<str2<<endl;
	return false;
}


void Initialize(char* str, char ch)
{
for(int i=0; i<l; i++)
		str[i]=ch;
}

int FindLength(char* str)
{
	return FindLength(str, '\n');
}

int FindLength(char* str, char ch)
{
	for(int i=0; i<l; i++)
	{
		
		if(str[i]==ch)
			return i;
		
	}
}

int cN(char nc)
{
	return int(nc)-48;
}

double ToNum(char *nstr, short digits)
{
	double N=0.0;

	
	for(int i=0; i<digits;i++)
	N+=cN(nstr[digits-1-i])*pow(10,(double)i);
	
return N;
}

double ToNum(char *nstr)
{
	double N=0.0;
	int size=FindLength(nstr,'\0');
	
	short dplace=FindChar(nstr,size,'.');

	if(dplace>-1)
		{
			char *tempn;
			double restore=pow(10,double((size-dplace)-1));
			tempn=new char[size-2];
			
			for(int i=0, j=0; i<size; i++)
			{if(nstr[i]!='.'){tempn[j]=nstr[i]; j++;}}

			tempn[size-1]='\0';
			
			return ToNum(tempn)/restore;

			
			delete[] tempn;
			return N;
		}

	for(int i=0; i<size;i++)
	{
		N+=cN(nstr[size-1-i])*pow(10,(double)i);
	}

return N;
}

char* CleanString(int size)
{
	char* NEW;
	NEW=new char[size]; 
	for(int i=0; i<size; i++)
		NEW[i]='\0';
	
	return NEW;
}



char* CleanString()
{
	return CleanString(l);
}

//exclusive between beg and end
char* Substr(char* str, int beg, int end)
{
	int sublength=(end-beg)-1;
	char* substr;
	substr=new char[sublength];
	beg++;//turn to begin of substr

	for(int i=0; i<sublength; i++)
	substr[i]=str[beg+i];

	substr[sublength]='\0';
	return substr;

}

char* AfterStr(char* line, int size, char s, int from)
{
	char *substr;
	int beg=0;
	int end=0;
	bool foundend=false;

	for(int i=from; i<size; i++)
	{

		if(line[i]==s)
		{
			beg=i;
			//now find end;
			for(int j=i+1; j<size-i; j++)
			{
				if(line[j]==s)
				{end=j;foundend=true;break;}
			}
		}

		if(foundend)
		{
		substr=Substr(line,beg,end);
		return substr;
		
		}
	}

}

int FindStr(char* str, char* fstr, int from)
{
	for(int i=from, j=0; str[i]!='\0'; i++)
	{
		if(str[i]==fstr[j])
			j++;
		else
		{
			if(j>0)
				{i-=j; j=0;}
		}

		if(fstr[j]=='\0')
			return i-j+1;
	}

	return -1;
}

int FindStr(char* str, char* fstr)
{
	return FindStr(str, fstr,0);
}

