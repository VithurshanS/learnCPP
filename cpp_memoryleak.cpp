#include <iostream>
#include "mem_leak.h"

void causeleak(){
	int* ptr = new int;
	*ptr = 22;
}

void perform_leak(){
	while (true){
		causeleak();
	}
}
