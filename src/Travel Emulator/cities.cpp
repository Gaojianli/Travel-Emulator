#include "cities.h"


cities::cities(String^ name):name(name){
	count++;
	this->id = count;
}