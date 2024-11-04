#pragma once

#include <freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "SolarSystemManager.h"
#include "ShipManager.h"

// GLUT related macros
#define FRAME_EXIST_TIME 1000 / 60
#define WIDTH 900
#define HEIGHT 600
#define Z_SUBDIVISION 100
#define Z_NEAR 0.1f 
#define Z_FAR 10000.0f

// Solar system render related macros
#define BASE_THETA_CHANGE 0.1f
#define CAMERA_INCREMENT 0.1f
#define ORBIT_SEGMENTS 1000  // Number of segments for smooth circle
#define PI 3.14159265358979323846

// Initial camera position
//GLfloat cameraPosition[] = { 0, 8, 0.1 }; // Top down
GLfloat cameraPosition[] = { 0, 0.5, 5 };

GLdouble cameraCenterX = 0;
GLdouble cameraCenterY = 0;
GLdouble cameraCenterZ = 0;

float theta = 0.0f;

int orbitOn = 0;

int starOn = 0;

void drawOrbit(float);

void drawOrbitHelper();

void drawEllipticalOrbit(float, float);

void renderPlanetEllipse(GLUquadric*, float, float, float, float, float, float, float);

void renderPlanet(GLUquadric*, float, float, float, float, float, float);

void renderPlanetWithMoon(GLUquadric*, GLUquadric*, float, float, float, float, float, float, float, float, float);

void renderSolarSystem();

void renderStars();

void renderShip();

void myDisplay();

void myKey(unsigned char, int, int);

void initializeGL();

void update();