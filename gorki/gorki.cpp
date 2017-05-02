#include "stdafx.h"
#include "stdafx.h"
#include <iostream> 
#include <windows.h>
#include <glut.h>   
#include "glaux.h"
#include <fstream>
#include  "koordinati.h"
#include "trajectoryandtrace.h"

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
	AUX_RGBImageRec *texture1 = auxDIBImageLoadA("nebo.bmp");
	glGenTextures(1, &textures[0]);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture1->sizeX, texture1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1->data);


	AUX_RGBImageRec *texture2 = auxDIBImageLoadA("trava.bmp");
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
		60.0,
		(GLfloat)w / h, 
		0.01, 10000.0);  
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
	glClearColor(0, 0, 1, 1);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glColor3f(1.0f, 1.0f, 1.0f);

	

	glPushMatrix();
	
	glScalef(3, 3, 3);
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
	glPushMatrix();


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthMask(GL_FALSE);
	
	glTranslatef(-2.5, -1, -0.5);
	glScalef(1, 4, 1);
	glColor4f(0, 0.8, 0.8, 0.5);
	glutSolidCube(1.0);
	
	

	glTranslatef(0, A, 0.0);
	glColor4f(0.8, 0.8, 0.8, 0.9);
	glScalef(0.9, 0.25, 0.9);
	glutSolidCube(1.0);
	glColor4f(0.8, 0.5, 0.5, 1.0);
	glutWireCube(1.0);
	
	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);

	glPopMatrix();
	glPushMatrix();

	glTranslatef(-2.5, -1, -0.5);
	glScalef(1, 4, 1);
	glColor4f(0.3, 0.3, 0.5, 1.0);
	glLineWidth(5);
	glutWireCube(1.0);


	glPopMatrix();
	const int sizeMasKoordinati = 5010;
	koordinati  *MasKoord[sizeMasKoordinati];
	for (int a=0; a<sizeMasKoordinati; a++)
	{
		MasKoord[a] = NULL;
	}
	int size = 0;
	size = sozdanieMassKoord(MasKoord, sizeMasKoordinati);
	postroenieTrassi(MasKoord, size);
	
	glFlush();
}





void Timer(int value)
{
	if ((A <= 0.3) && (k == 0))
	{
		A += 0.02;
	}
	else
	{
		k = 1;
		A -= 0.02;
	}
	if (A <- 0.3) k = 0;
	glutPostRedisplay();
	glutTimerFunc(50, Timer, 0);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);//Инициализация GLUT 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB
		| GLUT_DEPTH);//режим отображения информации
	glutInitWindowSize(500, 500);//Установка параметров окна
	glutCreateWindow("practica");//Создание окна
	init();
	glutReshapeFunc(reshape); //Установка функций, отвечающих за изменении формы окна
	glutDisplayFunc(display);//Установка функций, отвечающих за рисование в окне 
	glutMainLoop();//Вход в главный цикл GLUT
	
	return 0;
}