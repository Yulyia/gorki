#pragma once

#ifndef koordinati1
#define koordinati1


struct koordinati
{
	double x;
	double y;
	double z;
	koordinati(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	koordinati()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
};

#endif

