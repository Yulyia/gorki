

#include "stdafx.h"
#include "koordinati.h"
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <tchar.h>
#include <windows.h>

using namespace std;



koordinati::koordinati()
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE *p;
	char c, str[100000];
	int  j, i;
	cout << "������� ���� � �����: ";
	cin>>name;
	//��������,��� ������� ��������
	strcat(name, ".csv");
	ifstream fin(name);  // �������� ����� ��� ������
	if (!fin)

	{
		cout << endl << "������ �������� �����\n";
		cout << "������� ���� � ����� ��� ��� (��� ������� ������� ����� �������)\n";
	
	}
	cout << endl << "����� �����:\n";
	while (!fin.eof())
	{
		fin.getline(str, 100000); // ������ �����
		puts(str);
	}
	//��������,��� ������� ��������
	p = fopen(name, "r"); //�������� ������� ����
	j = 0;
	i = 0;
	if (p)
		while (!feof(p))
		{
			c = fgetc(p);
			if (c != ';')
			{
				mass[j][i] = c;
				i++;
			}
			else if ((i > 1) && (c == ';') && (mass[j][i - 1] != ';'))
			{
				j++;
				i = 0;
			}
		}

}





