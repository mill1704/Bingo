#include <stdio.h>
#include <GL\glut.h>      // (or others, depending on the system in use)
#include <cmath>
#include "Bingo.h"
#include <iostream>

#define RED 1.0,0.0,0.0		// RGB code for red color
#define WHITE_A 1.0,1.0,1.0,1.0 //REG code for white and alpha
Bingo bingo;
int colorMode = 0;
float phi = 3.14159265;
float deltaPhi = 0;
float dropPos = 0;

float unitWidth;
float unitHeight;
float unitx;
float unity;

// WCS volume limit
float left = -4;
float right = 4;
float bottom = -4;
float top = 4;
float znear = 0;
float zfar = -10.0;

float leftAspect = 0; 
float rightAspect = 0; 
float topAspect = 0; 
float bottomAspect = 0; 

// RCS for window  limit
int win_width = 400;
int win_height = 400;
float win_position_x = 0;
float win_position_y = 0;

// mouse position start
float xstart = 0;
float ystart = 0;

int MouseS = true;

void mouse(int button, int state, int x, int y) {
	float unit_x = (float)x / win_width * (rightAspect - leftAspect) + leftAspect;
	float unit_y = (float)(win_height - y) / win_height * (topAspect - bottomAspect) + bottomAspect;
	printf("mouse x=%d, y=%d, unit_x = %d, unit_y = %d\n", x, y, unit_x, unit_y);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		bingo.setCoinCurrentPosition(floor(unit_x + 0.5), floor(unit_y + 0.5));
		int currentx = (int)floor(unitx + 0.5);
		for (int j = 0; j < bingo.bingoBoard.nrow; j++) {
			
			if (bingo.bingoBoard.holes[currentx + 3][j].vacancy == false) {
				bingo.coinCurrent.setPosition(bingo.bingoBoard.holes[currentx + 3][j].x, bingo.bingoBoard.holes[currentx + 3][j].y);
				
				if (bingo.status == Bingo::Status::yellow)
				{
					bingo.coinsYellow.add(bingo.coinCurrent);
					bingo.coinCurrent.setColor(1, 0, 0);
					bingo.status = Bingo::Status::red;
					bingo.bingoBoard.coinStatus.setColor(1, 0, 0);
				}

				else
				{
					bingo.coinsRed.add(bingo.coinCurrent);
					bingo.coinCurrent.setColor(1, 1, 0);
					bingo.status = Bingo::Status::yellow;
					bingo.bingoBoard.coinStatus.setColor(1, 1, 0);

				}
				break;
			}
			else
			{
				continue;
			}
		}
	}
	
	glutPostRedisplay();
}

void motion(int x, int y)
{
	int unitWidth = rightAspect - leftAspect;
	int unitHeight = topAspect - bottomAspect;
	int unitx = (float)x / win_width * unitWidth - unitWidth / 2.0;
	int unity = (float)(win_height - y) / win_height * unitHeight - unitHeight / 2.0;
}


void passiveMotion(int x, int y) {
	if (MouseS == true) {
		unitWidth = rightAspect - leftAspect;
		unitHeight = topAspect - bottomAspect;
		unitx = (float)x / win_width * unitWidth + leftAspect;
		unity = (float)(win_height - y) / win_height * unitHeight + bottomAspect;
		bingo.setCoinCurrentPosition(unitx, unity);
		printf("x=%.3f, y=%.3f\n", unitx, unity);
		glutPostRedisplay();
	}
}


void init(void) {
	glClearColor(WHITE_A);                 // Set display-window color to white.
	glMatrixMode(GL_PROJECTION);           // Set projection parameters.
	glLoadIdentity();
	glOrtho(left, right, bottom, top, znear, zfar);
}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);            // Clear display window.
 	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	bingo.draw();
	glFlush();     // Process all OpenGL routines as quickly as possible.
}

void reshape(int w, int h) {
	// update display
	win_width = w;
	win_height = h;
	// calculate aspect ratio
	float aspect = (float)w / h;

	// set viewport
	glViewport(0, 0, w, h);

	// set matrix mode to projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (aspect >= 1.0) {
		leftAspect = left * aspect;
		rightAspect = right * aspect;
		bottomAspect = bottom;
		topAspect = top;
	}
	else {
		leftAspect = left;
		rightAspect = right;
		bottomAspect = bottom / aspect;
		topAspect = top / aspect;
	}
	glOrtho(leftAspect, rightAspect, bottomAspect, topAspect, znear, zfar);

	glutPostRedisplay();
}

void keyboard(unsigned char c, int w, int h) {
	switch (c) {
	
	default:break;
	}
	glutPostRedisplay();
}

void idle() {
	//red coin
	//dropPos -= redCoin.getDropStep();
	//redCoin.setYPosition(dropPos);

	//yellow coin
	//dropPos -= yellowCoin.getDropStep();
	//yellowCoin.setYPosition(dropPos);
	
	if (dropPos <= -3) {
		dropPos = -3;
	}

	glutPostRedisplay();

}

void main(int argc, char** argv) {
	// initializing routine
	glutInit(&argc, argv);                              // Initialize GLUT.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);        // Set display mode.
	glutInitWindowPosition(100, 100); //Set top-left display-window position.
	glutInitWindowSize(640, 480); // Set display-window width and height.
	glutCreateWindow("Bingo");     // Create display window.

											  //user initialization routine4051]
	init();						     		 // user initializing routine

																	//callback register function
	glutDisplayFunc(display);					// Send graphics to display window.
	glutMouseFunc(mouse);								// callback for mouse button and position
	glutMotionFunc(motion);							// callback for mouse motion
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);
	glutPassiveMotionFunc(passiveMotion);
	glutMainLoop();										// Loop over registered function
														// Display everything and wait.
}
