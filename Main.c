#include "Main.h"

void drawOrbit(float radius) {
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < ORBIT_SEGMENTS; i++) {
		float theta = 2.0f * PI * i / ORBIT_SEGMENTS;
		float x = radius * cosf(theta);
		float z = radius * sinf(theta);
		glVertex3f(x, 0.0f, z);
	}
	glEnd();
}

void drawOrbitHelper() {
	drawOrbit(PLANET_1_OFFSET_X);
	drawOrbit(PLANET_2_OFFSET_X);
	drawOrbit(PLANET_3_OFFSET_X);
	drawEllipticalOrbit(PLANET_4_OFFSET_X, 0.5f);
	drawOrbit(PLANET_5_OFFSET_X);
	drawOrbit(PLANET_6_OFFSET_X);
}

void drawEllipticalOrbit(float radiusX, float radiusZ) {
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < ORBIT_SEGMENTS; i++) {
		float theta = 2.0f * PI * i / ORBIT_SEGMENTS;
		float x = radiusX * cosf(theta);
		float z = radiusZ * sinf(theta); 
		glVertex3f(x, 0.0f, z);
	}
	glEnd();
}

void renderPlanetEllipse(GLUquadric* planet, float radiusX, float radiusZ, float planetRadius, float planetSpeed, float red, float green, float blue) {
	float x = radiusX * cosf(theta * planetSpeed);
	float z = radiusZ * sinf(theta * planetSpeed);
	glPushMatrix();
		glTranslatef(x, 0.0f, z);
		glColor3f(red, green, blue);
		gluSphere(planet, planetRadius, Z_SUBDIVISION, Z_SUBDIVISION);
	glPopMatrix();
}

void renderPlanet(GLUquadric* planet, float speed, float offsetX, float radius, float red, float green, float blue) {
	glPushMatrix();
		glRotatef(theta * speed, 0, 1, 0);
		glTranslatef(offsetX, 0, 0);
		glColor3f(red, green, blue);
		gluSphere(planet, radius, Z_SUBDIVISION, Z_SUBDIVISION);
	glPopMatrix();
}

void renderPlanetWithMoon(GLUquadric* planet,GLUquadric* moon, 
						  float planetSpeed, float moonSpeed,
						  float planetOffsetX, float planetRadius, float moonOffsetX, float moonRadius, 
	                      float red, float green, float blue) {
	glPushMatrix();
		// Planet
		glRotatef(theta * planetSpeed, 0, 1, 0);
		glTranslatef(planetOffsetX, 0, 0);

		if (orbitOn) {
			drawOrbit(planetOffsetX - moonOffsetX);
		}

		glColor3f(red, green, blue);
		gluSphere(planet, planetRadius, Z_SUBDIVISION, Z_SUBDIVISION);

		// Moon
		glRotatef(theta * moonSpeed / 2, 0, 1, 0);
		glTranslatef(planetOffsetX - moonOffsetX, 0, 0);
		glColor3f(1.0f - red, 1.0f - green, 1.0f - blue);
		gluSphere(moon, moonRadius, Z_SUBDIVISION, Z_SUBDIVISION);
	glPopMatrix();
}

void renderSolarSystem() {

	/* Render from innermost to outermost */
	glLoadIdentity();

	// Set the camera position to look at the origin, with the Y-axis as up
	gluLookAt(cameraPosition[0], cameraPosition[1], cameraPosition[2], cameraCenterX, cameraCenterY, cameraCenterZ, 0, 1, 0);

	// Sun
	glPushMatrix();
		glColor3f(1, 1, 0);  // Yellow
		gluSphere(sun, SUN_RADIUS, Z_SUBDIVISION, Z_SUBDIVISION);
	glPopMatrix();

	// Planets
	renderPlanetWithMoon(planet1, moon3, PLANET_1_SPEED, MOON_3_SPEED, PLANET_1_OFFSET_X, PLANET_1_RADIUS, MOON_3_OFFSET_X, MOON_3_RADIUS, 0, 1, 0);
	renderPlanet(planet2, PLANET_2_SPEED, PLANET_2_OFFSET_X, PLANET_2_RADIUS, 1, 0, 0);
	renderPlanetWithMoon(planet3, moon1, PLANET_3_SPEED, MOON_1_SPEED, PLANET_3_OFFSET_X, PLANET_3_RADIUS, MOON_1_OFFSET_X, MOON_1_RADIUS, 1, 0.5, 0);
	renderPlanetEllipse(planet4, PLANET_4_OFFSET_X, 0.5f, PLANET_4_RADIUS, PLANET_4_SPEED, 0, 0, 1);
	renderPlanetWithMoon(planet5, moon4, PLANET_5_SPEED, MOON_4_SPEED, PLANET_5_OFFSET_X, PLANET_5_RADIUS, MOON_4_OFFSET_X, MOON_4_RADIUS, 0.5, 0.3, 0.4);
	renderPlanetWithMoon(planet6, moon2, PLANET_6_SPEED, MOON_2_SPEED, PLANET_6_OFFSET_X, PLANET_6_RADIUS, MOON_2_OFFSET_X, MOON_2_RADIUS, 0.2, 0.4, 0.7);

	// Orbit
	if (orbitOn) {
		drawOrbitHelper();
	}
}

void myDisplay()
{
	// clear the screen 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	renderSolarSystem();

	// Swap the double buffers
	glutSwapBuffers();
}

void myKey(unsigned char key, int x, int y) {
	// User press 'q' to quit
	if (key == 'q') {
		printf("User press 'q'!\n");
		exit(0);
	}

	// User press 'q' to quit
	if (key == 'r') {
		orbitOn = 1 - orbitOn;
	}
}

void mySpecialKey(unsigned char key, int x, int y) {
	// Move camera up
	if (key == GLUT_KEY_UP) {
		cameraPosition[1] += CAMERA_INCREMENT;
		cameraCenterY += CAMERA_INCREMENT;
	}

	// Move camera down
	if (key == GLUT_KEY_DOWN) {
		cameraPosition[1] -= CAMERA_INCREMENT;
		cameraCenterY -= CAMERA_INCREMENT;
	}

	// Move camera left
	if (key == GLUT_KEY_LEFT) {
		cameraPosition[0] -= CAMERA_INCREMENT;
		cameraCenterX -= CAMERA_INCREMENT;
	}

	// Move camera right
	if (key == GLUT_KEY_RIGHT) {
		cameraPosition[0] += CAMERA_INCREMENT;
		cameraCenterX += CAMERA_INCREMENT;
	}

	// Move camera foward
	if (key == GLUT_KEY_PAGE_UP) {
		cameraPosition[2] -= CAMERA_INCREMENT;
		cameraCenterZ -= CAMERA_INCREMENT;
	}

	// Move camera backward
	if (key == GLUT_KEY_PAGE_DOWN) {
		cameraPosition[2] += CAMERA_INCREMENT;
		cameraCenterZ += CAMERA_INCREMENT;
	}
}

void myMouseButton(int button, int state, int x, int y) {

}

void initializeGL() {

	// Enable Depth testing
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	// Background set to block
	glClearColor(0, 0, 0, 1);

	// Set drawing color to be blue
	glColor3f(0.0, 0.0, 1.0);

	// Set matrix mode
	glMatrixMode(GL_PROJECTION);

	// Load the identity matrix
	glLoadIdentity();

	// Set camera projection to be perspective
	gluPerspective(45.0, (float)WIDTH / (float)HEIGHT, Z_NEAR, Z_FAR);

	// change into model-view mode so that we can change the object positions
	glMatrixMode(GL_MODELVIEW);
}

void update() {
	theta += BASE_THETA_CHANGE;
	glutPostRedisplay();
	glutTimerFunc(FRAME_EXIST_TIME, update, 0);
}

void main(int argc, char** argv)
{
	// Print out the control instructions
	printf("\n\n\nScreen Controls:\n");
	printf("----------------------\n");
	printf("r: toggle rings\n");
	printf("s: toggle stars\n");
	printf("c: toggle the sun's corona\n");
	printf("k: toggle shields\n");
	printf("q : quit\n\n\n");

	printf("Camera Controls:\n");
	printf("----------------------\n");
	printf("Up    Arrow: move up\n");
	printf("Down  Arrow: move down\n");
	printf("Right Arrow: move right\n");
	printf("Left  Arrow: move left\n");
	printf("PAGE  UP   : foward\n");
	printf("PAGE  DOWN : backward\n\n");

	// Set the seed for rand() function
	srand(time(NULL));

	// initialize the toolkit
	glutInit(&argc, argv);

	// Init the solar system
	initializeSolarSystemManager();

	// Set inital display properties
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(100, 150);

	// open the screen window
	glutCreateWindow("The Hitch Hikers Guide To The Planets");

	// register redraw function
	glutDisplayFunc(myDisplay);

	// register timer callback function
	glutTimerFunc(FRAME_EXIST_TIME, update, 0);

	// register normal keyboard input function
	glutKeyboardFunc(myKey);

	// register special keyboard input function
	glutSpecialFunc(mySpecialKey);

	// register mouse input function
	glutMouseFunc(myMouseButton);

	// Initialize OpenGL settings
	initializeGL();

	// Enter the program main loop
	glutMainLoop();
}