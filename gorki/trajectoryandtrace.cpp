#include "stdafx.h"
#include <stdlib.h>
#include <glut.h>   
#include "glaux.h"
#include "koordinati.h"
#include "trajectoryandtrace.h"
#include <fstream>



using namespace std;
int sozdanieMassKoord(koordinati *cordArray[], int  size)
{
	char fileName[] = "trajectory.csv";
	ifstream fileObject;
	fileObject.open(fileName);
	int loop1 = 0;
	while ((!fileObject.eof()) && (loop1< size))
	{
		double x, y, z;//это простые локальные переменные
		char charTemp1, charTemp2; //это дл€ точек с зап€той
								   //как объект УcinФ с консолью, так и УfileObjectФ c файлом
								   //Ёто C++, а не —и, так что тип double считаетс€ без проблем
		fileObject >> x >> charTemp1 >> y >> charTemp2 >> z;

		koordinati *Object1 = NULL;
		Object1 = new koordinati(x, y, z);
		cordArray[loop1] = Object1;
		loop1++;

	}

	fileObject.close();
	return loop1;
}




void postroenieTrassi(koordinati *mass[], int size)
{
	double AX0, AY0, AZ0, WidthTrace, A0D0, DX0, DY0, DZ0, A0E0, A0B0, BX0, BY0, BZ0, CX0, CY0, CZ0;
	double BX1, BY1, BZ1, CX1, CY1, CZ1, AX1, AY1, AZ1, A1D0, DX1, DY1, DZ1, A1E0, A1B0;
	double x = 0, y = 0, z = 0, x0 = 0, y0 = 0, z0 = 0, x1 = 0, y1 = 0, z1 = 0, x2 = 0, y2 = 0, z2 = 0;

	AX0 = 0; AZ0 = 0; WidthTrace = 0.3; A0D0 = 0; DX0 = 0; DZ0 = 0;
	A0E0 = 0; A0B0 = 0; BX0 = 0; BZ0 = 0; CX0 = 0; CZ0 = 0;
	BX1 = 0; BZ1 = 0; CX1 = 0; CZ1 = 0; AX1 = 0; AZ1 = 0;
	A1D0 = 0; DX1 = 0; DZ1 = 0; A1E0 = 0; A1B0 = 0;

	int loop1 = 0;

	for (loop1; loop1 < size - 2; loop1++)
	{
		x0 = mass[loop1]->x;
		z0 = mass[loop1]->y;
		y0 = mass[loop1]->z;

		x1 = mass[loop1 + 1]->x;
		z1 = mass[loop1 + 1]->y;
		y1 = mass[loop1 + 1]->z;

		x2 = mass[loop1 + 2]->x;
		z2 = mass[loop1 + 2]->y;
		y2 = mass[loop1 + 2]->z;


		AX0 = x1 - x0;
		AY0 = y1 - y0;

		DX0 = -AY0;
		DY0 = AX0;

		//длина вектора ј0D0
		A0D0 = sqrt(DX0*DX0 + DY0*DY0);
		if (A0D0 < 0.00004)
		{
			//A0D0 = 0.00004;
		}

		//единичный вектор
		double A0E0X = DX0 / A0D0;
		double A0E0Y = DY0 / A0D0;

		BX0 = (WidthTrace / 2.0) * A0E0X + x0;
		BY0 = (WidthTrace / 2.0) * A0E0Y + y0;

		CX0 = -1 * (WidthTrace / 2.0) * A0E0X + x0;
		CY0 = -1 * (WidthTrace / 2.0) * A0E0Y + y0;


		//расчЄт вершин дл€ точек ¬1 и —1
		AX1 = x2 - x1;
		AY1 = y2 - y1;
		DX1 = -AY1;
		DY1 = AX1;

		A1D0 = sqrt(DX1*DX1 + DY1*DY1);

		if (A1D0 < 0.00004)
		{
			//A1D0 = 0.00004;
		}

		double A1E1X = (1 / A1D0) * DX1;
		double A1E1Y = (1 / A1D0) * DY1;

		BX1 = (WidthTrace / 2.0) * A1E1X + x1;
		BY1 = (WidthTrace / 2.0) * A1E1Y + y1;

		CX1 = -1 * (WidthTrace / 2.0) * A1E1X + x1;
		CY1 = -1 * (WidthTrace / 2.0) * A1E1Y + y1;


		glBegin(GL_LINE_STRIP);
		glColor3d(0, 0, 0);
		glVertex3f(x0, z0, y0);
		glVertex3f(x1, z1, y1);
		glVertex3f(x2, z2, y2);
		glEnd();


		glShadeModel(GL_FLAT);
		glBegin(GL_TRIANGLE_FAN);
		glColor3d(0, 0, 0.9);
		glVertex3f(BX0, z0, BY0); //B0
		glVertex3f(CX0, z0, CY0); //C0
		glVertex3f(CX1, z1, CY1); //C1
		glColor3d(0, 0, 0.9);
		glVertex3f(BX1, z1, BY1); //B1 
		glEnd();

		const double q = -0.03;
		glBegin(GL_TRIANGLE_FAN);
		glColor3d(0.5, 0.9, 0.0);
		glVertex3f(BX0, z0 + q, BY0); //B0
		glVertex3f(CX1, z1 + q, CY1); //C1
		glVertex3f(CX0, z0 + q, CY0); //C0
		glColor3d(0.5, 0.9, 0.0);
		glVertex3f(BX1, z1 + q, BY1); //B1

		glEnd();
	}
}





