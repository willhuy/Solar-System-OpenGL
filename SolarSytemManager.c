#include "SolarSystemManager.h"

void initializeSolarSystemManager() {

	// Init all solar system content
	sun     = gluNewQuadric();
	planet1 = gluNewQuadric();
	planet2 = gluNewQuadric();
	planet3 = gluNewQuadric();
	planet4 = gluNewQuadric();
	planet5 = gluNewQuadric();
	planet6 = gluNewQuadric();
	moon1   = gluNewQuadric();
	moon2   = gluNewQuadric();
	moon3   = gluNewQuadric();
	moon4   = gluNewQuadric();
}