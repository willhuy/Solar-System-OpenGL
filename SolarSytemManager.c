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

void initStars() {
	for (int starIndex = 0; starIndex < NUMBER_OF_STAR; starIndex++) {
		// Position of stars on x, y, z axis
		starPosition[starIndex][0] = (rand() % 1000 - 500) / 10.0f;  // X position
		starPosition[starIndex][1] = (rand() % 1000 - 500) / 10.0f;  // Y position
		starPosition[starIndex][2] = (rand() % 1000 - 500) / 10.0f;  // Z position
	}
}