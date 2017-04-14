// gorki.cpp: ���������� ����� ����� ��� ����������� ����������.

#include "stdafx.h"
#include "stdafx.h"
#include <iostream> 
#include <windows.h>
#include <glut.h>   //����������� ���������� glut.h
#include "glaux.h"

#pragma comment(lib, "legacy_stdio_definitions.lib")
#pragma comment(lib, "opengl32.lib")      // ������ �� OpenGL32.lib 
#pragma comment(lib, "glu32.lib")      // ������ �� Glu32.lib 
#pragma comment(lib, "glaux.lib")      // ������ �� Glaux.lib

using namespace std;


unsigned int textures[2];

/* ��������� ��������� ���� */
float mat2_dif[] = { 0.0f,0.0f,0.8f };
float mat2_amb[] = { 0.2f,0.2f,0.2f };
float mat2_spec[] = { 0.6f,0.6f,0.6f };
float mat2_shininess = 0.7f * 128;

float B = -2.5;
int k = 0;


void LoadTextures()
{
	//AUX_RGBImageRec *texture1=auxDIBImageLoadA("D:\\���.bmp");

	AUX_RGBImageRec *texture1 = auxDIBImageLoadA("����.bmp");
	glGenTextures(1, &textures[0]);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture1->sizeX, texture1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1->data);


	AUX_RGBImageRec *texture2 = auxDIBImageLoadA("������.bmp");
	glGenTextures(1, &textures[1]);
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture2->sizeX, texture2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture2->data);

}


void reshape(int w, int h)
{
	/* ������������� ������ ������� ������
	* ������ ������� ����
	*/
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	/* ������ ������� �������� � ������ �������� ���� */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(
		40.0, /* ���� ������ � �������� */
		(GLfloat)w / h, /* ����������� ������ ���� */
		1, 100.0);  /* ���������� �� ���������� ��������� */
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	gluLookAt(
		0.0f, 0.0f, 8.0f, /* ��������� ������ */
		0.0f, 0.0f, 0.0f, /* ����� ����� */
		0.0f, 1.0f, 0.0f); /* ������������� ����������� ��� y */
}

/* �������������� ��������� ���������� �
* ��������� �����
*/
void init(void)
{
	LoadTextures();			// �������� �������
//	glEnable(GL_TEXTURE_2D);		// ���������� ��������� ��������

/*�� ������� ������ ��-�� ���������� ��������, ��� ��������� ���� � ��������� ��������� - ��
���������� ������*/
	glClearColor(0.8, 0.8, 0.8, 0);
	GLfloat light_ambient[] = { 0.3, 0.8, 0.0, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	/* ������������� ��������� ��������� ����� */
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	/* �������� ��������� � �������� ����� */
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	/* �������� z-����� */
	glEnable(GL_DEPTH_TEST);

}

void display(void)
{
	/* ������� ����� ����� � ����� ������� */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(20.0, 1.0, 0.0, 0.0);


	/* ���������� ��� - ���� � �������*/
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat2_amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat2_dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat2_spec);
	glMaterialf(GL_FRONT, GL_SHININESS, mat2_shininess);

	glPushMatrix();
	glTranslatef(-2, B, 0.0);
	glRotatef(270.0, 1.0, 0.0, 0.0);
	glutSolidCube(1.0);
	glPopMatrix();



	/* ���� ������� ��� �� ����������� ���������� � ���������������� �� - 
	����� ������, ������� - ����.
	�� ������-�� �������� � ���� �� ����� ������������ � ���((
		glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textures[1]);		  //  �������� ����

	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 0.0, -1);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0.0, 1.0, -1);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, -1);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(1.0, 0.0, -1);
	glEnd();
	*/
	glPopMatrix();

	/* ������� ����� �� ����� */
	glFlush();
}


void Timer(int value)
{

	if ((B <= 0.75) && (k == 0))
	{
		B += 0.02;
	}
	else
	{
		k = 1;
		B -= 0.02;
	}
	if (B < -3) k = 0;
	glutPostRedisplay();
	glutTimerFunc(50, Timer, 0);
}

/* ������� ���� ����������.
* ��������� ����, ��������������� �����
* ������ � ������� �������
*/
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
	glutTimerFunc(1000, Timer, 0);
	glutMainLoop();
	return 0;
}