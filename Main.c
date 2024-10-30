#include "Main.h"

void renderPlanet(GLUquadric* planet, float speed, float offsetX, float radius, float red, float green, float blue) {
	glPushMatrix();
		glRotatef(theta * speed, 0, 1, 0);
		glTranslatef(offsetX, 0, 0);
		glColor3f(red, green, blue);
		gluSphere(planet, radius, Z_SUBDIVISION, Z_SUBDIVISION);
	glPopMatrix();
}

void renderSolarSystem() {

	/* Render from innermost to outermost */
	glLoadIdentity();

	// Set the camera position to look at the origin, with the Y-axis as up
	gluLookAt(cameraPosition[0], cameraPosition[1], cameraPosition[2], 0, 0, 0, 0, 1, 0);

	// Sun
	glPushMatrix();
	glColor3f(1, 1, 0);  // Yellow
	gluSphere(sun, SUN_RADIUS, Z_SUBDIVISION, Z_SUBDIVISION);
	glPopMatrix();

	// Planets
	renderPlanet(planet1, PLANET_1_SPEED, PLANET_1_OFFSET_X, PLANET_1_RADIUS, 0, 1, 0); // Green Planet
	renderPlanet(planet2, PLANET_2_SPEED, PLANET_2_OFFSET_X, PLANET_2_RADIUS, 1, 0, 0); // Red Planet
	renderPlanet(planet3, PLANET_3_SPEED, PLANET_3_OFFSET_X, PLANET_3_RADIUS, 1, 0.5, 0); // Orange Planet
	renderPlanet(planet4, PLANET_4_SPEED, PLANET_4_OFFSET_X, PLANET_4_RADIUS, 1, 0, 0); // Red Planet
	renderPlanet(planet5, PLANET_5_SPEED, PLANET_5_OFFSET_X, PLANET_5_RADIUS, 1, 0, 0); // Red Planet
	renderPlanet(planet6, PLANET_6_SPEED, PLANET_6_OFFSET_X, PLANET_6_RADIUS, 1, 0, 0); // Red Planet
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

}

void myMouseButton(int button, int state, int x, int y) {

}

void initializeGL() {
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
	gluPerspective(100.0, (float)WIDTH / (float)HEIGHT, Z_NEAR, Z_FAR);

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

	// register keyboard input function
	glutKeyboardFunc(myKey);

	// register mouse input function
	glutMouseFunc(myMouseButton);

	// Initialize OpenGL settings
	initializeGL();

	// Enter the program main loop
	glutMainLoop();
}