/*
#include<stdio.h>
#include <GL/gl.h>
#include <gl/glut.h>
#include <sstream>
#include "shape/Sphere.h"
#include "glm/matrix.hpp"
#include "Camera/CameraFPSEuler.h"
#include <iomanip>
#include <fstream>
#define KEY_ESC 27 /* GLUT doesn't supply this */

int fullscreen = 0;
int mouseDown = 0;

float xrot = 100.0f;
float yrot = -100.0f;

float xdiff = 100.0f;
float ydiff = 100.0f;

//Cube Trasformation
float tra_x = 0.0f;
float tra_y = 0.0f;
float tra_z = 0.0f;

//Sphere Transformation
float trans_x = 0.0f;
float trans_y = 0.0f;
float trans_z = 0.0f;


float grow_shrink = 70.0f;
float resize_f = 1.0f;

void drawSphere()
{
	glTranslatef(trans_x,trans_y ,trans_z );
	
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f( 0.5f, -0.5f, 0.5f);
	glVertex3f( 0.5f, 0.5f, 0.5f);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	// BACK
	glVertex3f(0.5f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f( 0.5f, 0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f, -0.5f);

	glColor3f(0.0f, 1.0f, 0.0f);
	// LEFT
	glVertex3f(1.0f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	// RIGHT
	glVertex3f( 0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, 0.5f, -0.5f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f( 0.5f, 0.5f, 0.5f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f( 0.5f, -0.5f, 0.5f);

	glColor3f(0.0f, 0.0f, 1.0f);
	// TOP
	glVertex3f(-0.5f, 1.5f, 0.5f);
	glVertex3f( 0.5f, 0.5f, 0.5f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f( 0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glColor3f(1.0f, 0.0f, 0.0f);
	// BOTTOM
	glVertex3f(1.5f, 0.5f, -0.5f);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f, 0.5f);
	glEnd();
}

void drawBox()
{

	
	glTranslatef(tra_x, tra_y, tra_z);

	glBegin(GL_QUADS);
	
	

	glColor3f(1.0f, 0.0f, 0.0f);
	// FRONT
	glVertex3f(0.5f, -0.5f, 0.5f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f( 0.5f, -0.5f, 0.5f);
	glVertex3f( 0.5f, 0.5f, 0.5f);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	// BACK
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f( 0.5f, 0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f, -0.5f);

	glColor3f(0.0f, 1.0f, 0.0f);
	// LEFT
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	// RIGHT
	glVertex3f( 0.0f, 0.5f, -0.5f);
	glVertex3f( 0.5f, 0.5f, -0.5f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f( 0.5f, 0.5f, 0.5f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f( 0.5f, -0.5f, 0.5f);

	glColor3f(0.0f, 0.0f, 1.0f);
	// TOP
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f( 0.5f, 0.5f, 0.5f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f( 0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glColor3f(1.0f, 0.0f, 0.0f);
	// BOTTOM
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f, 0.5f);
	glEnd();
}

int init(void)
{
	glClearColor(0.93f, 0.93f, 0.93f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearDepth(1.0f);

	return 1;
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(
	0.0f, 0.0f, 3.0f,
	0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f);

	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);

	drawBox();
	drawSphere();
	//drawTriangle();

	glFlush();
	glutSwapBuffers();
}

void resize(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(grow_shrink, resize_f * w / h, resize_f, 100 * resize_f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}




