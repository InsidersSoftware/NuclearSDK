#include<stdio.h>
#include <GL/gl.h>
#include <gl/glut.h>
#include <sstream>
#include "shape/Sphere.h"
#include "glm/matrix.hpp"
#include "Camera/Camera.h"
#include <iomanip>
#include <fstream>
#define KEY_ESC 27 /* GLUT doesn't supply this */

int fullscreen = 0;
int mouseDown = 0;

float trans_x = 0.0f;
float trans_y = 0.0f;
float trans_z = 0.0f;

void display()
{
	
}


void idle(void)
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}

	glutPostRedisplay();
}


void mySpecialFunction(int key, int x, int y)
{
    //if (key == GLUT_KEY_F1)
    //{
        printf("U -----------> rotate clockwise\n");
        printf("Y -----------> rotate counter clockwise\n");
        printf("W or w ------> Up\n");
        printf("S or s -----> Down\n");
        printf("D or d ------> Right\n");
        printf("A or a ------> Left\n");
        printf("Z or z ------> Shrink\n");
        printf("X or x ------> Grow\n");
        printf("Escape Key ---> exit the program\n\n");
    //}
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27 : 
			exit(1); 
			break;

			

		case 'w':
		case 'W':
			tra_x += 1.0f;
			break;
		case 's':
		case 'S':
			tra_x -= 1.0f;
			break;
		case 'a':
		case 'A':
			tra_z -= 1.0f;
			break;
		case 'd':
		case 'D':
			tra_z += 1.0f;
			break;
		case 'u':
		case 'U':
			xrot += 1.0f;
			yrot += 1.0f;
			xdiff += 1.0f;
			ydiff += 1.0f;
			break;

		case 'y':
		case 'Y':
			xrot -= 1.0f;
			yrot -= 1.0f;
			xdiff += 1.0f;
			ydiff += 1.0f;
			break;

		case 'h':
		case 'H':
			mySpecialFunction(key, x, y);
			break;
		case 'Z':
		case 'z':
			grow_shrink--;
			resize(500, 500);
			
			break;
		case 'X':
		case 'x':
			grow_shrink++;
			resize(500, 500);
			
			break;

	}

	
	glutPostRedisplay();
}

void specialKeyboard(int key, int x, int y)
{
	if (key == GLUT_KEY_F1)
	{
		fullscreen = !fullscreen;

		if (fullscreen)
			glutFullScreen();
		else
		{
			glutReshapeWindow(500, 500);
			glutPositionWindow(50, 50);
		}
	}
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = 1;

		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
		mouseDown = 0;
}

void mouseMotion(int x, int y)
{
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;

		glutPostRedisplay();
	}
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
     
    printf("Window Succesfully Launched\n");
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutCreateWindow("Nuclear");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutReshapeFunc(resize);
	//glutIdleFunc(idle);

	if (!init())
		return 1;

	glutMainLoop();
} 


