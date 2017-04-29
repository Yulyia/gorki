#include "stdafx.h"
#include <stdlib.h>
#include <glut.h>   
#include "glaux.h"
#include "koordinati.h"
#include "trajectoryandtrace.h"
#include <fstream>



using namespace std;

double sozdMass()
{
	const int sizeMasKoordinati = 5010;
	char fileName[] = "trajectory.csv";
	koordinati *masKoordinati[sizeMasKoordinati];
	double A[sizeMasKoordinati][3];
	//	glFrustum(false);
	ifstream fileObject;
	fileObject.open(fileName);
	int loop1 = 0;
	while (!fileObject.eof())
	{
		double x, y, z;//это простые локальные переменные
		char charTemp1, charTemp2; //это дл€ точек с зап€той
										   //как объект УcinФ с консолью, так и УfileObjectФ c файлом
								   //Ёто C++, а не —и, так что тип double считаетс€ без проблем
		fileObject >> x >> charTemp1 >> y >> charTemp2 >> z;

		koordinati *onePoint = new koordinati(x, y, z);//а это использование конструктора с трем€ параметрами
													   //ниже код уже вам писал
		masKoordinati[loop1] = onePoint;

		 A[loop1][1] = masKoordinati[loop1]->x;
		 A[loop1][2] = masKoordinati[loop1]->y;
		 A[loop1][3] = masKoordinati[loop1]->z;
		loop1++;
	}
	return A[loop1][3];
	fileObject.close();
}


int razmer()
{
	const int sizeMasKoordinati = 5010;
	char fileName[] = "trajectory.csv";
	koordinati *masKoordinati[sizeMasKoordinati];
	double A[sizeMasKoordinati][3];
	//	glFrustum(false);
	ifstream fileObject;
	fileObject.open(fileName);
	int loop1 = 0;
	while (!fileObject.eof())
	{
		double x, y, z;//это простые локальные переменные
		char charTemp1, charTemp2; //это дл€ точек с зап€той
								   //как объект УcinФ с консолью, так и УfileObjectФ c файлом
								   //Ёто C++, а не —и, так что тип double считаетс€ без проблем
		fileObject >> x >> charTemp1 >> y >> charTemp2 >> z;

		koordinati *onePoint = new koordinati(x, y, z);//а это использование конструктора с трем€ параметрами
													   //ниже код уже вам писал
		masKoordinati[loop1] = onePoint;

		A[loop1][1] = masKoordinati[loop1]->x;
		A[loop1][2] = masKoordinati[loop1]->y;
		A[loop1][3] = masKoordinati[loop1]->z;
		loop1++;
	}
	return loop1;
	fileObject.close();
}



void postr(double * mass, int razmer)
{
	double AX0, AY0, WidthTrace, A0D0, DX0, DY0, A0E0, A0B0, BX0, BY0, CX0, CY0;
	double BX1, BY1, CX1, CY1, AX1, AY1, A1D0, DX1, DY1, A1E0, A1B0;
	double x = 0, y = 0, z = 0, x0 = 0, y0 = 0, z0 = 0, x1 = 0, y1 = 0, z1 = 0, x2 = 0, y2 = 0, z2 = 0;

	AX0 = 0; AY0 = 0; WidthTrace = 0.2; A0D0 = 0; DX0 = 0; DY0 = 0;
	A0E0 = 0; A0B0 = 0; BX0 = 0; BY0 = 0; CX0 = 0; CY0 = 0;
	BX1 = 0; BY1 = 0; CX1 = 0; CY1 = 0; AX1 = 0; AY1 = 0;
	A1D0 = 0; DX1 = 0; DY1 = 0; A1E0 = 0; A1B0 = 0;

	int loop1 = 0;

	for (loop1; loop1 < razmer - 2; loop1++)
	{
		x0 = mass[loop1][1];
		y0 = mass[loop1][2];
		z0 = mass[loop1][3];


		x1 = mass[loop1 + 1][1];
		y1 = mass[loop1 + 1][2];
		z1 = mass[loop1 + 1][3];



		x2 = mass[loop1 + 2][1];
		y2 = mass[loop1 + 2][2];
		z2 = mass[loop1 + 2][3];
		

		AX0 = x1 - x0;
		AY0 = y1 - y0;
		//не уверена на счЄт поворота
		DX0 = AX0 * 0 - AY0 * 1;
		DY0 = AX0 * 1 + AY0 * 0;
		//длина вектора ј0D0
		A0D0 = sqrt(DX0*DX0 + DY0*DY0);
		//однонаправленный вектор
		A0E0 = (1 / A0D0) * A0D0;
		A0B0 = (WidthTrace / 2.0) * A0E0;
		BX0 = A0B0 + AX0;
		BY0 = A0B0 + AY0;
		CX0 = (--A0B0) + AX0;
		CY0 = (--A0B0) + AY0;

		//расчЄт вершин дл€ точек ¬1 и —1
		AX1 = x2 - x1;
		AY1 = y2 - y1;
		DX1 = AX1 * 0 - AY1 * 1;
		DY1 = AX1 * 1 + AY1 * 0;
		A1D0 = sqrt(DX1*DX1 + DY1*DY1);
		A1E0 = (1 / A0D0) * A0D0;
		A1B0 = (WidthTrace / 2.0) * A1E0;
		BX1 = A1B0 + AX1;
		BY1 = A1B0 + AY1;
		CX1 = (--A1B0) + AX1;
		CY1 = (--A1B0) + AY1;


		//не пойму почему не соедин€ютс€ каждые три вершины
		//они вывод€тс€ правильно по координатам, но тройками
		glBegin(GL_LINE_STRIP);
		glColor3d(0, 0, 0);
		glVertex3f(x0, y0, z0);
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
		glEnd();

		loop1++;
	}
}





