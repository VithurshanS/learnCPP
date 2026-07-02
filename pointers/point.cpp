#include <iostream>



void pointy(){
	int* n =new int{5};
	std::cout<<"n is pointing to value " <<*n<<" *n address is "<<&(*n)<<std::endl;
	int x = 8;
	n=&x;
	std::cout<<"n is pointing to value " <<*n<<" address of x "<<&x<<std::endl;
}

int main(){
	pointy();
}
