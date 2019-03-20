#include "cities.h"


cities::cities(String^ name):name(name){
	count++;
	this->id = count;
}

cities::cities(int id, String ^ name):id(id),name(name) { 
	count++;
 }
