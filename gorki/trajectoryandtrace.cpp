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
	double AX0, AZ0, WidthTrace, A0D0, DX0, DZ0, A0E0, A0B0, BX0, BZ0, CX0, CZ0;
	double BX1, BZ1, CX1, CZ1, AX1, AZ1, A1D0, DX1, DZ1, A1E0, A1B0;
	double x = 0, y = 0, z = 0, x0 = 0, y0 = 0, z0 = 0, x1 = 0, y1 = 0, z1 = 0, x2 = 0, y2 = 0, z2 = 0;

	AX0 = 0; AZ0 = 0; WidthTrace = 0.8; A0D0 = 0; DX0 = 0; DZ0 = 0;
	A0E0 = 0; A0B0 = 0; BX0 = 0; BZ0 = 0; CX0 = 0; CZ0 = 0;
	BX1 = 0; BZ1 = 0; CX1 = 0; CZ1 = 0; AX1 = 0; AZ1 = 0;
	A1D0 = 0; DX1 = 0; DZ1 = 0; A1E0 = 0; A1B0 = 0;

	int loop1 = 0;

	for (loop1; loop1 < size - 2; loop1++)
	{
		x0 = mass[loop1]->x;
		y0 = mass[loop1]->y;
		z0 = mass[loop1]->z;

		x1 = mass[loop1 + 1]->x;
		y1 = mass[loop1 + 1]->y;
		z1 = mass[loop1 + 1]->z;

		x2 = mass[loop1 + 2]->x;
		y2 = mass[loop1 + 2]->y;
		z2 = mass[loop1 + 2]->z;


		AX0 = x1 - x0;
		AZ0 = z1 - z0;

		DX0 = -AZ0;
		DZ0 = AX0;

		//длина вектора ј0D0
		A0D0 = sqrt(DX0*DX0 + DZ0*DZ0);
		
		//единичный вектор
		float A0E0X = DX0 / A0D0;
		float A0E0Y = DZ0 / A0D0;

		BX0 = (WidthTrace / 2.0) * A0E0X + x0;
		BZ0 = (WidthTrace / 2.0) * A0E0Y + z0;

		CX0 = -1 * (WidthTrace / 2.0) * A0E0X + x0;
		CZ0 = -1 * (WidthTrace / 2.0) * A0E0Y + z0;


		//расчЄт вершин дл€ точек ¬1 и —1
		AX1 = x2 - x1;
		AZ1 = z2 - z1;
		DX1 = -AZ1;
		DZ1 = AX1;

		A1D0 = sqrt(DX1*DX1 + DZ1*DZ1);

		float A1E1X = (1 / A1D0) * DX1;
		float A1E1Z = (1 / A1D0) * DZ1;

		BX1 = (WidthTrace / 2.0) * A1E1X + x1;
		BZ1 = (WidthTrace / 2.0) * A1E1Z + z1;

		CX1 = -1 * (WidthTrace / 2.0) * A1E1X + x1;
		CZ1 = -1 * (WidthTrace / 2.0) * A1E1Z + z1;
		
		
		glBegin(GL_LINE_STRIP);
		glColor3d(0, 0, 0);
		glVertex3f(x0, y0, z0);
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
		glEnd();
		

		glShadeModel(GL_FLAT);
		glBegin(GL_TRIANGLE_STRIP);
		glColor3d(0, 0, 0.5);
		glVertex3f(BX0, y0, BZ0); //B0
		glVertex3f(CX0, y0, CZ0); //C0
		glVertex3f(CX1, y1, CZ1); //C1
		glColor3d(0, 0, 0.9);
		glVertex3f(BX1, y1, BZ1); //B1 
			
		const double q = -0.3;
		glColor3d(0, 0.5, 0.5);
		glVertex3f(BX0, y0, BZ0 +q); //B0
		glVertex3f(CX1, y1, CZ1 + q); //C1
		glVertex3f(CX0, y0, CZ0 + q); //C0
		glColor3d(0.5, 0.9, 0.0);
		glVertex3f(BX1, y1, BZ1 + q); //B1

		glEnd();
	}
}





