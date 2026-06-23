#include <iostream>
#include "variable_initialization.h"

// rule do not explicitly init a variable with in a function because initially it wqill get allocated by a garbage value

void variable_init()
{
	//copy initialization
	int a = 5;
	//direct initialization
	int b(4.9);
	// brace init
	int c{};
	std::cout<<"a,b,c are "<<a<<" "<<b<<" "<<c<<std::endl;

}
