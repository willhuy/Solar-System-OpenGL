#pragma once

#include <freeglut.h>

#define SUN_RADIUS         0.2f

/* Planets */

#define PLANET_1_RADIUS    0.03f
#define PLANET_1_SPEED     10
#define PLANET_1_OFFSET_X  0.6f

#define PLANET_2_RADIUS    0.07f
#define PLANET_2_SPEED     5
#define PLANET_2_OFFSET_X  1.0f

#define PLANET_3_RADIUS    0.10f
#define PLANET_3_SPEED     25
#define PLANET_3_OFFSET_X  1.5f

#define PLANET_4_RADIUS    0.08f
#define PLANET_4_SPEED     0.5
#define PLANET_4_OFFSET_X  1.9f

#define PLANET_5_RADIUS    0.07f
#define PLANET_5_SPEED     7
#define PLANET_5_OFFSET_X  2.4f

#define PLANET_6_RADIUS    0.07f
#define PLANET_6_SPEED     10
#define PLANET_6_OFFSET_X  2.9f

/* Moons */

#define MOON_1_RADIUS    0.02f
#define MOON_1_SPEED     3
#define MOON_1_OFFSET_X  1.3f

#define MOON_2_RADIUS    0.02f
#define MOON_2_SPEED     5
#define MOON_2_OFFSET_X  2.7f

#define MOON_3_RADIUS    0.01f
#define MOON_3_SPEED     1
#define MOON_3_OFFSET_X  0.4f

#define MOON_4_RADIUS    0.03f
#define MOON_4_SPEED     5
#define MOON_4_OFFSET_X  2.1f

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