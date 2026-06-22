#include <iostream>
#include "const_initialization.h"

// rule do not explicitly init a variable with in a function because initially it wqill get allocated by a garbage value

void const_init(){
	const int max_users = 100;
// max_users = 101; // COMPILER ERROR: Cannot reassign a const.
	constexpr int grid_size = 10 * 10; // compiler time calculation
	std::cout<<"max_users and gridsize are "<<max_users<<" "<<grid_size<<" "<<std::endl;

}
