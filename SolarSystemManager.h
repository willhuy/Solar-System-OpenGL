#pragma once

#include <freeglut.h>

#define SUN_RADIUS         0.2f

#define PLANET_1_RADIUS    0.05f
#define PLANET_1_SPEED     50
#define PLANET_1_OFFSET_X  0.5f

#define PLANET_2_RADIUS    0.07f
#define PLANET_2_SPEED     20
#define PLANET_2_OFFSET_X  0.7f

#define PLANET_3_RADIUS    0.15f
#define PLANET_3_SPEED     25
#define PLANET_3_OFFSET_X  0.9f

#define PLANET_4_RADIUS    0.02f
#define PLANET_4_SPEED     10
#define PLANET_4_OFFSET_X  1.0f

#define PLANET_5_RADIUS    0.07f
#define PLANET_5_SPEED     60
#define PLANET_5_OFFSET_X  1.2f

#define PLANET_6_RADIUS    0.07f
#define PLANET_6_SPEED     30
#define PLANET_6_OFFSET_X  2.0f

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