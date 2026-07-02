#include <iostream>
#include <string>
#include <variant>
using namespace std;

struct Animal {
    virtual ~Animal() = default;
    virtual string communicate() const = 0;
};

struct Horse: public Animal {
    virtual string communicate() const { return "neigh"; }
};

struct Cat: public Animal {
    virtual string communicate() const { return "meow"; }
};

struct Dog: public Animal {
    virtual string communicate() const { return "bark"; }
};

void makeSounds(const Animal& animal) {
    animal.communicate();
}


void makeSound(variant<Horse, Cat, Dog> animal){
	visit([](auto& a){
	auto sound = a.communicate();
	std::cout << sound <<std::endl;
	}, animal);
};

int main(){
	makeSound(Cat{});
};
