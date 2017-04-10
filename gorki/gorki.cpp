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



void Initialize()
{

	glClearColor(1.0, 1.0, 1.0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();



	glOrtho(-1,1,-1,1,-1,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}





void Draw()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);// ������������� ������ ���������
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLineWidth(4);
	glBegin(GL_LINE_STRIP);

		glColor3d(1, 0, 0);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(0.1f, 0.5f, 0.0f);
		glVertex3f(0.2f, 0.5f, 0.1f);
		glVertex3f(0.3f, 0.5f, 0.3f);
		glVertex3f(0.4f, 0.3f, 0.4f);
		glVertex3f(0.5f, 0.2f,0.05f);
		glVertex3f(0.3f, 0.0f, 0.6f);

	glEnd();



	glutSwapBuffers();
	glFlush();
}

//����� � ������� ����
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);		//��������� ������ ����
	glutInitWindowPosition(350, 150);	//������� ����
	glutCreateWindow("������������ ������ ");//��� ����
	Initialize();						//����� ������� Initialize
	glutDisplayFunc(Draw);				//����� ������� ���������
	glutMainLoop();//����������� ����
	return 0;
}
