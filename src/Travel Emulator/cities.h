//cities.h The city class
#pragma once
#include<string>
#include <iostream>
using namespace std;
class cities
{
public:
	int id;
	std::string name;
	cities(string name);
private:
	static int count;
};

