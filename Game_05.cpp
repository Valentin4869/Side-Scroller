
#include "stdafx.h"
#include "Functions.h"

\
#include <stdio.h>
 #include <stdlib.h>
 
 #include <GL/gl.h>
#include <GL/glu.h>
 #include <GL/glut.h>
 
#include "Data.h"

OPENFILENAMEA GetOFN2(char* filep)
{

	OPENFILENAMEA ofn2;
	ZeroMemory( &ofn2 , sizeof( ofn2));
	ofn2.lStructSize = sizeof ( ofn2 );

	ofn2.hwndOwner = NULL ;
	ofn2.lpstrFile = filep;
	ofn2.lpstrFile[0] = '\0';
	ofn2.nMaxFile = 200;
	ofn2.lpstrFilter = "All\0*.*\0Level Data\0*.LD\0";
	ofn2.nFilterIndex =1;
	ofn2.lpstrFileTitle = NULL ;
	ofn2.nMaxFileTitle = 0 ;
	ofn2.lpstrInitialDir="C:\\Users\\Dell\\Documents\\Visual Studio 2010\\Projects\\Game\0" ;
	ofn2.Flags = OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST ;

	return ofn2;

}


int main(int argc, char **argv)
{
	
	
	WTitle=argv[0];
	
	srand((int)time(0));


        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 
        glutInitWindowPosition(350, 50);
		glutInitWindowSize((int)width, (int)height);
		
		//glShadeModel(GL_SMOOTH);

         
	    MainMenu();    
		//HideWindow(argv[0]);
        glutMainLoop();
		
 // Options();
        return 0;
}
 

 
