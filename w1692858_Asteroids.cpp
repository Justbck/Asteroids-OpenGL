
#pragma once
#include "include\freeglut.h"
#include <iostream>
#include <cmath>
#include <math.h>
#include <time.h> 
#include <string>
#include <string.h>
#include <stdio.h>



// static width and hight of the screen
GLfloat w = 600, h = 600;
using namespace std;

#define PI 3.14159
#define X_CENTRE 0.0      
#define Y_CENTRE 0.0
#define LENGTH   1.0  



//booleans that specify witch function is currently displayed
//start screen is always at the begining when you run the program
bool grid = true;
bool pattern = true;
bool startGame = false;
bool gamePaused = true;
bool game = true;
bool shoot = true;
bool gameOver = true;
bool bulletShoot = true;
bool isCollied = true;
//OBJECT MOVEMENT


//angles of ship, asteroids, enables rotation
GLfloat angle1 = 0.0;
GLfloat angle = 0.0;
GLfloat xr = 0, yr = 0;
//shooting properties
GLfloat shootPoint;
GLfloat mRadius = 0.01;
int score = 0;
//randomly regerated asteroid properties(see main() for randomization)
GLfloat astRadius;
GLfloat astPosX;
GLfloat astPosY;



// arrays that hold values to diffrenciete asteroid properites from the ones that were generally generated

//shades
GLfloat color[10]{
	0.1,0.3,-0.9,
	0.6,-0.1,0.5,
	-0.7,0.2,0.9,
	-1.0,
};


//speed
GLfloat angle2[20]{
	0.1,0.00004,0.1,0.009,
	0.000000006,0.01,0.2,0.5,
	0.001,0.3,0.005,0.8,
	0.4,0.07,0.00000001,0.6,
};



//shape
GLint segments[20]{
	6,4,5,4,3,
	7,4,5,15,6,
	4,7,7,8,6,
	4,5,5,9,6,
};

//radius/size
GLfloat radius[20]{
	0.09,0.0,0.05,
	0.1,0.0,0.11,
	0.12,0.05,0.06,
	0.02,0.05,0.1,
	0.0,0.02,0.0,
	0.05,0.1,0.13
};


//position x 
GLfloat xPos[20]{
	-0.2,-0.3,-0.7,
	0.5,-0.8,-0.5,
	-0.9,-0.4,-0.3,
	-0.2,-0.9,0.3,
	-0.5,-0.8,0.5,
	-0.4,-0.3,-0.9
};


//position y
GLfloat yPos[20]{
	-0.5,0.5,-0.7,
	0.5,0.2,0.3,
	-0.8,-0.4,0.3,
	-0.2,0.5,-0.3,
	0.5,0.6,0.3,
	0.4,-0.9,0.7

};


//time
int refreshmill = 1;

//random values for creating effect in the start/pause/exit screen
int randX, randY, randS;
float r, g, b;

//values of colors
GLfloat red = 1.0, green = 1.0, blue = 1.0;


//drawing functions
void drawShip(GLfloat radius, GLfloat x, GLfloat y);
void drawCircle(GLfloat radius, GLfloat x, GLfloat y, int numSegments);
void explodeAsteroid(GLfloat radius, GLfloat x, GLfloat y, int numSegments);
void rotateAsteroid(GLfloat radius, GLfloat x, GLfloat y, int numSegments, GLfloat angle);
void menu(GLint value);
void drawPoint();
void drawPattern();
void drawBullet(GLfloat radius, GLfloat x, GLfloat y, int numSegments);


//pattern triangles
void drawPattern() {

	glColor4f(0.09, 0.09, 0.09, 0.3);
	// x- / y+
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex2f(-1.0, 1.0);
	glVertex2f(-1.0, 0.5);
	glVertex2f(-0.5, 0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.5, 1.0);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.0, 0.5);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex2f(-0.5, 0.5);
	glVertex2f(-0.5, 0.0);
	glVertex2f(0.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-1.0, 0.5);
	glVertex2f(-1.0, 0.0);
	glVertex2f(-0.5, 0.0);
	glEnd();

	//+x +y
	glBegin(GL_POLYGON);
	glVertex2f(1.0, 1.0);
	glVertex2f(1.0, 0.5);
	glVertex2f(0.5, 0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.5, 1.0);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.0, 0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(1.0, 0.5);
	glVertex2f(1.0, 0.0);
	glVertex2f(0.5, 0.0);
	glEnd();


	glColor4f(0.2, 0.2, 0.2, 0.1);
	//+x -y
	glBegin(GL_POLYGON);
	glVertex2f(1.0, -0.5);
	glVertex2f(1.0, 0.0);
	glVertex2f(0.5, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(1.0, -1.0);
	glVertex2f(1.0, -0.5);
	glVertex2f(0.5, -0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.5, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.5, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.0, -0.5);
	glVertex2f(0.5, -1.0);
	glEnd();


	//-x -y

	glBegin(GL_POLYGON);
	glVertex2f(-1.0, -1.0);
	glVertex2f(-1.0, -0.5);
	glVertex2f(-0.5, -0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -1.0);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.0, -0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.0);
	glVertex2f(0.0, 0.0);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex2f(-1.0, -0.5);
	glVertex2f(-1.0, 0.0);
	glVertex2f(-0.5, 0.0);
	glEnd();
}



void drawGrid() {


	//light grey
	glColor3f(0.3, 0.3, 0.3);


	//repating lines
	for (float line = 0; line < 11; line++) {


		glPushMatrix();
		glBegin(GL_LINES);

		//-x,-y
		glVertex2f(0.0, -line / 10);
		glVertex2f(-1.0, -line / 10);
		glVertex2f(-line / 10, 0.0);
		glVertex2f(-line / 10, -1.0);

		//+x,+y
		glVertex2f(0.0, line / 10);
		glVertex2f(1.0, line / 10);
		glVertex2f(line / 10, 0.0);
		glVertex2f(line / 10, 1.0);


		//-x,+y
		glVertex2f(0.0, line / 10);
		glVertex2f(-1.0, line / 10);
		glVertex2f(-line / 10, 0.0);
		glVertex2f(-line / 10, 1.0);


		//+x.-y
		glVertex2f(0.0, -line / 10);
		glVertex2f(1.0, -line / 10);
		glVertex2f(line / 10, -0.0);
		glVertex2f(line / 10, -1.0);

		glEnd();
	}

}





void reshape(int width, int height)
{

	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width <= height) {
		glOrtho(-1.0,1.0,-1.0/aspect,1.0/aspect,-1.0,1.0);
	}
	else {
		glOrtho(-1.0*aspect, 1.0 *aspect, -1.0 , 1.0, -1.0, 1.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		

	}
}

void menu(GLint value) {

	//glut menu values

	//pattern display
	if (value == 1) {
		glClearColor(0.0, 0.0, 0.0, 0.0);
		grid = 1.0;
		pattern = 0.0;
		startGame = 1.0;
		game = 0.0;
		gameOver = 1.0;
	}

	//grid display
	if (value == 2) {
		glClearColor(0.0, 0.0, 0.0, 0.0);
		grid = 0.0;
		pattern = 1.0;
		startGame = 1.0;
		game = 0.0;
		gameOver = 1.0;
	}

	//clear screen
	if (value ==3){
		glClearColor(0.0, 0.0, 0.0, 0.0);
		grid = 1.0;
		pattern = 1.0;
		startGame = 1.0;
		game = 0.0;
		gameOver = 1.0;
	}

}



//DISPLAY TEXT
void displayRasterText(float x, float y, float z, char* stringToDisplay) {
	int length;
	glRasterPos3f(x, y, z);
	length = strlen(stringToDisplay);

	for (int i = 0; i < length; i++) {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, stringToDisplay[i]);
	}
}

void displayRasterText15(float x, float y, float z, char* stringToDisplay) {
	int length;
	glRasterPos3f(x, y, z);
	length = strlen(stringToDisplay);

	for (int i = 0; i < length; i++) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, stringToDisplay[i]);
	}
}

//timer function - refreshes program enables rotation
void timer(int value) {

	glutPostRedisplay();
	glutTimerFunc(refreshmill, timer, 0);
}

//radom points as an decoration effect outside the game

void idle()
{
	glLoadIdentity();
	glPushMatrix();

	randX = rand() % 400;
	randY = rand() % 400;
	randS = rand() % 20;

	r = (float)((rand() % 9)) / 8;
	g = (float)((rand() % 9)) / 8;
	b = (float)((rand() % 9)) / 8;


	glPopMatrix();
	glutSwapBuffers();
}


//decoration - random colorful points

void drawPoint() {

	gluOrtho2D(0.0, 400.0, 0.0, 400.0);

	glPushMatrix();

	glColor3f(r, g, b);
	glPointSize(randS);
	glBegin(GL_POINTS);
	glVertex2i(randX, randY);
	glEnd();
	glPopMatrix();

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);   /* clear window */
	//BACKGROUND

	if (!startGame) {
		//startScreenDisplay();

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		drawPoint();

		glColor3f(1, 1, 1);

		displayRasterText15(X_CENTRE - 0.3 * LENGTH, Y_CENTRE + 0.1 * LENGTH, 1.0, " A S T E R O I D S ");
		displayRasterText(X_CENTRE - 0.30 * LENGTH, Y_CENTRE - 0.1 * LENGTH, 1.0, "press S to start game");
		displayRasterText(X_CENTRE - 0.15 * LENGTH, Y_CENTRE - 0.3 * LENGTH, 1.0, "@w1692858");
	}
	
	if (!grid) {
		drawGrid();
	}

	if (!pattern) {
		drawPattern();
	}

	if (!gamePaused) {

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();

		drawPoint();
		glColor3f(1, 1, 1);

		displayRasterText15(X_CENTRE - 0.3 * LENGTH, Y_CENTRE + 0.1 * LENGTH, 1.0, " G A M E  P A U S E D  ");
		displayRasterText(X_CENTRE - 0.22 * LENGTH, Y_CENTRE - 0.1 * LENGTH, 1.0, "press S to continue");

	}

	if (!gameOver) {

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();

		drawPoint();
		glColor3f(1, 1, 1);

		displayRasterText15(X_CENTRE - 0.3 * LENGTH, Y_CENTRE + 0.1 * LENGTH, 1.0, " G A M E  O V E R ");
		displayRasterText(X_CENTRE - 0.22 * LENGTH, Y_CENTRE - 0.1 * LENGTH, 1.0, "your score: 0");

	}





	//start game
	if (!game) {


		//putting ship in a matrix so it can move and roatate
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glPushMatrix();
		glTranslatef(0.0, xr, yr);
		glRotatef(angle, 0.0, 0.0, 1.0);

		//DRAWS SHIP
		drawShip(0.09, 0.0, 0.0);

		//adding shoot to the matrix so that it moves and rotates with the shop


		//is shoot is not called the radius i 0.0 so its like it does not exist - collision is not possible
		//it cannot destroy asteroid
		if (shoot){
			mRadius = 0.0;

		}

		if (!shoot) {

			//bullet size increase - visible - colission is possible
			mRadius = 0.01;
			glColor3f(red, 0.0, 1.0);

				//drawing many bullets
				for (int j = 0; j < 9; j++) {

					if (yr >= 0) {
						drawBullet(mRadius, xr, yr, 5);

					}
					//when ship is turned upside down the bullet poits change its direction accoring to the ship position
					if (yr < 0) {
						drawBullet(mRadius, xr, -yr, 5);
					}
				
				
			}
		}

		if (!bulletShoot) {
			shoot = 1.0;
		}


		//display score
		glColor3f(1, 1, 1);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		displayRasterText(X_CENTRE - 0.9 * LENGTH, Y_CENTRE + 0.85 * LENGTH, 0.5, "SCORE: 0");

		glPopMatrix();
		glutSwapBuffers();
		
		
		// draw random asteroids
		int i = 0;
		//number of asteroids
		for (int k = 0; k < 5; k++) {

				//random color + shade from the array 
				glColor3f(red + color[i], green + color[i], blue + color[i]);
				//random atributes + posiotion from array
				rotateAsteroid(astRadius + radius[i], astPosX + xPos[i], astPosY + yPos[i], segments[i], angle2[i]);
				//more different asteroids
				i++;

				//collision
				if (!isCollied) {
					//explosion - astreroid destruction
					explodeAsteroid(astRadius + radius[i], astPosX + xPos[i], astPosY + yPos[i], segments[i]);
				}
			}


		// collision
		if (astPosX + xPos[i] < xr +mRadius &&
			astPosX + xPos[i] + astRadius + radius[i] > xr &&
			astPosY < yr +mRadius &&
			astPosY + astRadius + radius[i] > yr) {
			
			isCollied = 0.0;
		}

		glPopMatrix();
		glutSwapBuffers();

		glPopMatrix();
		glutSwapBuffers();
	}

	glFlush();
}


//CHOICE FROM THE KEYBOARD

void NormalKeyHandler(unsigned char key, int x, int y) {

	switch (key) {

	//shoot by space bar
	case ' ':
	
		shoot = 0.0;
		break;

		//start game
	case 's':
		gameOver = 1.0;
		game = 0.0;
		startGame = 1.0;
		gamePaused = 1.0;
		break;

		//pasue game
	case'p':

		gameOver = 1.0;
		game = 1.0;
		startGame = 1.0;
		gamePaused = 0.0;
		pattern = 1.0;
		grid = 1.0;
		break;

		//exit 
	case 'e':

		gameOver = 0.0;
		game = 1.0;
		startGame = 1.0;
		gamePaused = 1.0;
		pattern = 1.0;
		grid = 1.0;
		break;



	default:
		break;
	}
	//glutSwapBuffers();

}

void specialKey(int key, int x, int y) {


	switch (key) {

	//ship up
	case GLUT_KEY_UP:
		yr = yr + 0.01;
		shoot= 1.0;
		break;

	//ship down
	case GLUT_KEY_DOWN:
		yr = yr - 0.01;
		shoot = 1.0;
		break;

	//ship rotate left
	case GLUT_KEY_LEFT:
		angle = angle + 7;
		shoot = 1.0;
		break;


	//ship rotate right
	case GLUT_KEY_RIGHT:
		angle = angle - 7;
		shoot = 1.0;
		break;

	default:
		break;

	}
}


//draw circle - mesh for asteroid and bullets
void drawCircle(GLfloat radius, GLfloat x, GLfloat y, int numSegments) {


	GLfloat x1, y1;

	glBegin(GL_POLYGON);

	for (int i = 0; i < numSegments; i++) {

		float t = 2.0 * 3.14 * float(i) / float(numSegments);
		float x1 = radius * cosf(t);
		float y1 = radius * sinf(t);
		glVertex2f(x1 + x, y1 + y);
	}
	glEnd();
}


//bullet drawing and movement
void drawBullet(GLfloat radius, GLfloat x, GLfloat y, int numSegments) {


	glMatrixMode(GL_MODELVIEW);

	for (int l = 0; l < 10; l++) {
		for (int j = 2; j < 3; j++) {
			glPushMatrix();
			
				glTranslatef(x, y + 0.1 * l* j, 0.0);
				glRotatef(angle1, 0.0, 0.0, 0.0);
				glTranslatef(-x, -(y * l * j), 0.0);
				drawCircle(radius, x, y, numSegments);
		
			glPopMatrix();
			angle1 += 0.3;
		}
	}

}

//ship drawing - modified code from the tutorial star
void drawShip(GLfloat radius, GLfloat x, GLfloat y)
{
	//x1,y1 is the top coordinate
	glColor3f(0.0, 1.0, 1.0);
	GLfloat x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;

	x = xr;
	y = yr;

	glColor3f(1.0, 1.0, 1.0);

	x1 = x * radius;
	y1 = y + radius;
	x2 = (x + 0.99 * radius) / 20;
	y2 = y + 0.01 * radius;
	x3 = x + 0.75 * radius;
	y3 = y - 0.65 * radius;
	x4 = x - 0.75 * radius;
	y4 = y - radius * 0.65;
	x5 = (x - 0.99 * radius) / 20;
	y5 = y + 0.01 * radius;

	glLineWidth(1.0);
	glBegin(GL_LINES);
	glVertex2f(x1 + xr, y1 + yr); // line outside
	glVertex2f(x3 + xr, y3 + yr);

	glVertex2f(x1 + xr, y1 + yr);
	glVertex2f(x4 + xr, y4 + yr);

	glVertex2f(x2 + xr, y2 + yr); // line inside
	glVertex2f(x4 + xr, y4 + yr);


	glVertex2f(x3 + xr, y3 + yr);
	glVertex2f(x5 + xr, y5 + yr);

	glEnd();
}

//asteroid explosion - modified rotation code
void explodeAsteroid(GLfloat radius, GLfloat x, GLfloat y, int numSegments) {

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(x, y, 0.0);
	glRotatef(angle1, 0.0, 0.0, 0.0);
	glTranslatef(-x, -y, 0.0);


	drawCircle(radius, x, y, numSegments);

	glPopMatrix();
	glutSwapBuffers();
	angle1 += 0.1;
	

}


//rotation - angle adds up each time its display
void rotateAsteroid(GLfloat radius, GLfloat x, GLfloat y, int numSegments, GLfloat angle) {


	//glLoadIdentity();
	glPushMatrix();
	glTranslatef(x, y, 0.0);
	glRotatef(angle1, 0.0, 0.0, 1.0);
	glTranslatef(-x, -y, 0.0);
	drawCircle(radius, x, y, numSegments);
	glPopMatrix();
	glutPostRedisplay();
	//glutSwapBuffers();
	//speed
	angle1 += angle;

}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
int main(int argc, char** argv)
{

	//console instruction
	cout << "------------GAME INSTRUCTIONS------------" << endl
		<< "" << endl;
	cout << "1) Use arrows to move and rotate the ship" << endl;
	cout << "2) Use spacebar to shoot asteroid" << endl;
	cout << "3) Press p to pause the game" << endl;
	cout << "4) Press e to exit the game" << endl
		<< "" << endl;
	cout << "------------------ENJOY!-----------------" << endl;


	//random each time program runs
	srand(time(0));

	red = (float)((rand() % 6)) / 8;
	green = (float)((rand() % 9)) / 8;
	blue = (float)((rand() % 9)) / 8;

	astRadius = (float)((rand() % 2)) /30;
	astPosX = (float)((rand() % 5)) /10;
	astPosY = (float)((rand() % 5)) /10;



	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Asteroids");

	int sub1 = glutCreateMenu(menu);
	init();


	glutKeyboardFunc(NormalKeyHandler);
	glutSpecialFunc(specialKey);

	glutTimerFunc(1, timer, 0);
	glutReshapeFunc(reshape);


	glutDisplayFunc(display);
	glutAddMenuEntry("pattern", 1);
	glutAddMenuEntry("grid", 2);
	glutAddMenuEntry("exit", 3);
	glutCreateMenu(menu);
	glutAddSubMenu("background", sub1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}















