#include "stdafx.h"
#include "koordinati.h"
#include <stdlib.h>
#include <fstream>



using namespace std;


 void koordinati::koord()
{
	const int sizeMasKoordinati = 5010;
	char fileName[] = "trajectory.csv";
	koordinati *masKoordinati[sizeMasKoordinati];

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
		//
		//ƒоступ к значени€м напоминаю:
		// double tempValue = masKoordinati[loop1]->x;
		//
		loop1++;
	}
	fileObject.close();
	
}





