#include "cpp_initialization.h"
#include <iostream>

int define_wo_init(){
	int a;
	std::cout<<"address is "<<&a<<std::endl;
	std::cout<<"value is "<<a<<std::endl;
	return 0;
}
