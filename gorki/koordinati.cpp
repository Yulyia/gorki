

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
	cout << "Введите путь к файлу: ";
	cin>>name;
	//ругается,что функция устарела
	strcat(name, ".csv");
	ifstream fin(name);  // Открытие файла для чтения
	if (!fin)

	{
		cout << endl << "Ошибка открытия файла\n";
		cout << "Введите путь к файлу еще раз (для повтора нажмите любую клавишу)\n";
	
	}
	cout << endl << "Текст файла:\n";
	while (!fin.eof())
	{
		fin.getline(str, 100000); // Чтение файла
		puts(str);
	}
	//ругается,что функция устарела
	p = fopen(name, "r"); //создание массива слов
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





