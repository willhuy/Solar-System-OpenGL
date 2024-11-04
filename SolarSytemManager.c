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

// Generate random rays for the corona
void generateCorona() {
	for (int i = 0; i < NUMBER_OF_CORONA; i++) {
		float angle = (rand() % 360) * (PI / 180.0f);  // Random angle in radians
		coronas[i][0] = cos(angle) * SUN_RADIUS; // Corona x coor
		coronas[i][1] = sin(angle) * SUN_RADIUS; // Corona y coor
		coronas[i][2] = 0.2f + (rand() % 50) / 50.0f;  // Random length
		coronas[i][3] = 0.5f + (rand() % 50) / 100.0f;  // Random transparency
	}
}