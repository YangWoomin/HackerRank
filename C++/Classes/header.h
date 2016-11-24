#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <vector>
#include <map>

using namespace std;

// Box_it!
class Box;
ostream& operator<<(ostream& o, Box& box);
void check2();

// Exceptional server
class Server;
void exceptional_server();

// Abstract class - Cache
void cacheTest();
