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
		double x, y, z;//��� ������� ��������� ����������
		char charTemp1, charTemp2; //��� ��� ����� � �������

								   //��� ������ �cin� � ��������, ��� � �fileObject� c ������
								   //��� C++, � �� ��, ��� ��� ��� double ��������� ��� �������
		fileObject >> x >> charTemp1 >> y >> charTemp2 >> z;

		koordinati *onePoint = new koordinati(x, y, z);//� ��� ������������� ������������ � ����� �����������
													   //���� ��� ��� ��� �����
		masKoordinati[loop1] = onePoint;
		//
		//������ � ��������� ���������:
		// double tempValue = masKoordinati[loop1]->x;
		//
		loop1++;
	}
	fileObject.close();
	
}





