
#include "stdafx.h"
#include "stdafx.h"
#include <iostream> 
#include <windows.h>
#include <glut.h>   
#include "glaux.h"

#pragma comment(lib, "legacy_stdio_definitions.lib")
#pragma comment(lib, "opengl32.lib")      // Nnueea ia OpenGL32.lib 
#pragma comment(lib, "glu32.lib")      // Nnueea ia Glu32.lib 
#pragma comment(lib, "glaux.lib")      // Nnueea ia Glaux.lib



using namespace std;



float A = 0.0;
int k = 0;

unsigned int textures[6];

void LoadTextures()
{
	AUX_RGBImageRec *texture1 = auxDIBImageLoadA("небо.bmp");
	glGenTextures(1, &textures[0]);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture1->sizeX, texture1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1->data);


	AUX_RGBImageRec *texture2 = auxDIBImageLoadA("травка.bmp");
	glGenTextures(1, &textures[1]);
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture2->sizeX, texture2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture2->data);
	}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(
		40.0,
		(GLfloat)w / h, 
		1, 100.0);  
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	gluLookAt(
		0.0f, 0.0f, 8.0f,
		0.0f, 0.0f, 0.0f, 
		0.0f, 1.0f, 0.0f);
}


void init(void)
{
	LoadTextures();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

}

void display(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glPushMatrix();
	
	//исправила ошибку
	glScalef(1.5, 1.5, 1.5);

	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glColor3f(1.0f, 1.0f, 1.0f);
	
	glBegin(GL_QUADS);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0f, 1.0f, -1.0f);          // Право верх квадрата (Верх)
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0f, 1.0f, -1.0f);          // Лево верх
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.0f, 1.0f, 1.0f);          // Лево низ
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0f, 1.0f, 1.0f);          // Право низ
	glEnd();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textures[1]);

	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0f, -1.0f, 1.0f);          // Верх право квадрата (Низ)
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0f, -1.0f, 1.0f);          // Верх лево
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.0f, -1.0f, -1.0f);          // Низ лево
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0f, -1.0f, -1.0f);          // Низ право
	glEnd();




	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0f, -1.0f, -1.0f);          // Верх право квадрата (Зад)
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0f, -1.0f, -1.0f);          // Верх лево
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.0f, 1.0f, -1.0f);          // Низ лево
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0f, 1.0f, -1.0f);          // Низ право
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-1.0f, 1.0f, 1.0f);          // Верх право квадрата (Лево)
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0f, 1.0f, -1.0f);          // Верх лево
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.0f, -1.0f, -1.0f);          // Низ лево
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-1.0f, -1.0f, 1.0f);          // Низ право
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0f, 1.0f, -1.0f);          // Верх право квадрата (Право)
	glTexCoord2f(0.0, 1.0);
	glVertex3f(1.0f, 1.0f, 1.0f);          // Верх лево
	glTexCoord2f(0.0, 0.0);
	glVertex3f(1.0f, -1.0f, 1.0f);          // Низ лево
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0f, -1.0f, -1.0f);          // Низ право
	glEnd();

	glPopMatrix();

	glFlush();
}



void Timer(int value)
{
	++A ;
	glutPostRedisplay();
	glutTimerFunc(50, Timer, 0);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB
		| GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
//	glutTimerFunc(1000, Timer, 0);
	glutMainLoop();
	return 0;
}