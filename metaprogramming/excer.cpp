#include <iostream>
#include <variant>
template<int N>
int product() {
	if constexpr (N<2){return 1;}
    	else{return N * product<N-1>();}
}

int main(){
	std::cout << product<5>() << std::endl;
	auto tmp = std::variant<std::string, double>{4.};
	tmp = 6;

	return 0;
}
