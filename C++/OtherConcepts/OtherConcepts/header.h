#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// operator overload
class Matrix {
public:
	vector<vector<int>>a;
	Matrix& operator+(Matrix& other);
};
void operator_overload();

// overload operator
class Complex;
void overload_operator();

// attending workshop
typedef struct _Workshop {
	int start_time;
	int duration;
	int end_time;
} Workshop;
class Available_Workshops;
Available_Workshops* initialize(int* start_time, int* duration, int size);
int CalculateMaxWorkshops(Available_Workshops* aw);
void attending_workshop();