// gorki.cpp: определяет точку входа для консольного приложения.

#include "stdafx.h"
#include "stdafx.h"
#include <iostream> 
#include <windows.h>
#include <glut.h>   //Подключение библиотеки glut.h
#include "glaux.h"

#pragma comment(lib, "legacy_stdio_definitions.lib")
#pragma comment(lib, "opengl32.lib")      // Ссылка на OpenGL32.lib 
#pragma comment(lib, "glu32.lib")      // Ссылка на Glu32.lib 
#pragma comment(lib, "glaux.lib")      // Ссылка на Glaux.lib

using namespace std;


unsigned int textures[2];

/* параметры материала куба */
float mat2_dif[] = { 0.0f,0.0f,0.8f };
float mat2_amb[] = { 0.2f,0.2f,0.2f };
float mat2_spec[] = { 0.6f,0.6f,0.6f };
float mat2_shininess = 0.7f * 128;

float B = -2.5;
int k = 0;


void LoadTextures()
{
	//AUX_RGBImageRec *texture1=auxDIBImageLoadA("D:\\фон.bmp");

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
	/* устанавливаем размер области вывода
	* равным размеру окна
	*/
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	/* задаем матрицу проекции с учетом размеров окна */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(
		40.0, /* угол зрения в градусах */
		(GLfloat)w / h, /* коэффициент сжатия окна */
		1, 100.0);  /* расстояние до плоскостей отсечения */
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	gluLookAt(
		0.0f, 0.0f, 8.0f, /* положение камеры */
		0.0f, 0.0f, 0.0f, /* центр сцены */
		0.0f, 1.0f, 0.0f); /* положительное направление оси y */
}

/* Инициализируем параметры материалов и
* источника света
*/
void init(void)
{
	LoadTextures();			// Загрузка текстур
//	glEnable(GL_TEXTURE_2D);		// Разрешение наложение текстуры

/*не понимаю почему из-за разрешения текстуры, все настройки фона и освещения сбиваются - всё
становится темнее*/
	glClearColor(0.8, 0.8, 0.8, 0);
	GLfloat light_ambient[] = { 0.3, 0.8, 0.0, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	/* устанавливаем параметры источника света */
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	/* включаем освещение и источник света */
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	/* включаем z-буфер */
	glEnable(GL_DEPTH_TEST);

}

void display(void)
{
	/* очищаем буфер кадра и буфер глубины */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(20.0, 1.0, 0.0, 0.0);


	/* отображаем куб - лифт в будущем*/
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat2_amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat2_dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat2_spec);
	glMaterialf(GL_FRONT, GL_SHININESS, mat2_shininess);

	glPushMatrix();
	glTranslatef(-2, B, 0.0);
	glRotatef(270.0, 1.0, 0.0, 0.0);
	glutSolidCube(1.0);
	glPopMatrix();



	/* хочу сделать куб из графических примитивов и затекстурировать их - 
	внизу травка, побокам - небо.
	Но почему-то квадраты в упор не хотят превращаться в куб((
		glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textures[1]);		  //  текстура фона

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

	/* выводим сцену на экран */
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

/* Главный цикл приложения.
* Создается окно, устанавливается режим
* экрана с буфером глубины
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