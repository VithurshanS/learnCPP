#include <iostream>
#include <array>

template<std::size_t N>
struct unroller{
	template<typename F>
	static constexpr auto run(F func){
		return func(N) + unroller<N-1>::run(func);
	}
	
};

template<>
struct unroller<0>{
	template<typename F>
        static constexpr auto run(F func){ 
                return func(0);
        }
};

template<typename T, auto N>
T sumOfPositive(const std::array<T, N>& v){
	auto getInd = [&](auto i){
		if(v[i] > 0){
			return v[i];
		}
		return 0;};
	T sum = unroller<N-1>::run(getInd);
	return sum;

}

int main(){
	const std::array<int,4> q = {1,-2,5,3};
	auto xx = sumOfPositive(q);
	std::cout<<"sum is "<<xx<<std::endl;
	return 0;
}
