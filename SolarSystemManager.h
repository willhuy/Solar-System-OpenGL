#pragma once

#include <freeglut.h>

#define SUN_RADIUS       0.15

#define PLANET_1_RADIUS  0.05
#define PLANET_1_SPEED   20
//#define PLANET_2_RADIUS
//#define PLANET_3_RADIUS
//#define PLANET_4_RADIUS
//#define PLANET_5_RADIUS
//#define PLANET_6_RADIUS
//#define MOON_1_RADIUS
//#define MOON_2_RADIUS
//#define MOON_3_RADIUS
//#define MOON_4_RADIUS

GLUquadric* sun;
GLUquadric* planet1;
GLUquadric* planet2;
GLUquadric* planet3;
GLUquadric* planet4;
GLUquadric* planet5;
GLUquadric* planet6;
GLUquadric* moon1;
GLUquadric* moon2;
GLUquadric* moon3;
GLUquadric* moon4;

void initializeSolarSystemManager();