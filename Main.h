#pragma once

#include <freeglut.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#include "SolarSystemManager.h"

// GLUT related macros
#define FRAME_EXIST_TIME 1000 / 60
#define WIDTH 900
#define HEIGHT 600

void myDisplay();

void myMouseButton(int, int, int, int);

void myKey(unsigned char, int, int);

void initializeGL();

void update();