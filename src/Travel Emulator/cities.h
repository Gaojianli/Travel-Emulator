//cities.h The city class
#pragma once
using namespace System;
ref class cities
{
public:
	int id;
	String^ name;
	cities(String^ name);
private:
	static int count=0;
};

