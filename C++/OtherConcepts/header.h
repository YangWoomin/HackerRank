#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <list>
#include <bitset>
#include <array>

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

// class template specialization
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };
template <typename T> struct Traits;
void class_template_specialization();

// c++ variadics
void variadics();

// bit array
void bit_array();
