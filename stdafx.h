// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#define PI 3.14159265359
#define DEFAULT_LENGTH 20


const double g=9.8*150;		//gravity
enum State{JUMPING=1, FALLING=2, MOVING=0};
enum direction{RIGHT=0, LEFT=2, UP=3, DOWN=1};
enum Axis{X,Y,Z};
enum key{right,down,left,up,jump};

#include "targetver.h"

#include <windows.h> 
#include <GL/gl.h> 
#include <GL/glu.h>
#include <GL/glut.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <cmath>

using namespace std;





// TODO: reference additional headers your program requires here
