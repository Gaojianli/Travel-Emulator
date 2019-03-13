#include "cities.h"


cities::cities(string name):name(name){
	count++;
	this->id = count;
}
int cities::count = 0;