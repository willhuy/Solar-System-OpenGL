#pragma once

#include <freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "SolarSystemManager.h"

// GLUT related macros
#define FRAME_EXIST_TIME 1000 / 60
#define WIDTH 900
#define HEIGHT 600
#define Z_NEAR 0.1f 
#define Z_FAR 10000.0f

// Solar system render related macros
#define Z_SUBDIVISION 100
#define BASE_THETA_CHANGE 0.1f
#define ORBIT_SEGMENTS 1000  // Number of segments for smooth circle
#define PI 3.14159265358979323846

// Initial camera position
//GLfloat cameraPosition[] = { 0, 5, 0.1 }; // Top down
GLfloat cameraPosition[] = { 0, 0.5, 5 };

float theta = 0.0f;

void drawOrbit(float);

void renderPlanet(GLUquadric*, float, float, float, float, float, float);

void renderPlanetWithMoon(GLUquadric*, GLUquadric*, float, float, float, float, float, float, float, float, float);

void renderSolarSystem();

void myDisplay();

void myMouseButton(int, int, int, int);

void myKey(unsigned char, int, int);

void initializeGL();

void update();