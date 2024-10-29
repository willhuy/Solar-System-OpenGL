#include "Main.h"

void myDisplay()
{
	// clear the screen 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1, 0, 0);
	GLUquadric* sun = gluNewQuadric();
	gluSphere(sun, 0.10006, 100, 100);

	// Swap the double buffers
	glutSwapBuffers();
}

void myKey(unsigned char key, int x, int y) {

}

void myMouseButton(int button, int state, int x, int y) {

}


void initializeGL() {
	// Background set to block
	glClearColor(0, 0, 0, 1);

	// Set drawing color to be blue
	glColor3f(0.0, 0.0, 1.0);

	// Set matrix mode
	glMatrixMode(GL_PROJECTION);

	// Load the identity matrix
	glLoadIdentity();
	
	// set window mode to 2D orthographic 
	//glOrtho(-2.0, 2.0, -2.0, 2.0, -10, 10.0);

	gluPerspective(45, (float)WIDTH / (float)HEIGHT, 0.1, 1000.0);

	// change into model-view mode so that we can change the object positions
	glMatrixMode(GL_MODELVIEW);
}

void update() {
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
