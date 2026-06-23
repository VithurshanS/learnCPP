#include <iostream>
#include "math_utilities.h"
#include "cpp_initialization.h"
#include "mem_leak.h"
#include "variable_initialization.h"
#include "const_initialization.h"
#include "myvector.h"
int main(){
	//int result = add(4,7);
	//std::cout << "the result is "<< result << std::endl;	
	//define_wo_init();
	//perform_leak();
	variable_init();
	//const_init();
	auto v = myvector<int>();
	v.add(4);
	v.add(10);
	v.add(10);
	v.print();
	//std::cout<<"v.data is " << v.retdata() << std::endl;
	v.getcompletememorymap();
	return 0;
}
