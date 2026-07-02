#include <iostream>
#include <initializer_list>
#include <algorithm>

template <typename T>
class CustomVector {
private:
    T* data;
    size_t current_size;

public:
    // =================================================================
    // Constructor 1: Size Initialization (Direct Initialization)
    // Triggered by Parentheses: CustomVector<int> vec(5);
    // =================================================================
    CustomVector(size_t n) {
        current_size = n;
        data = new T[current_size];
        
        // When setting a size, it's best practice to zero-initialize the memory
        for (size_t i = 0; i < current_size; ++i) {
            data[i] = T(); // This puts a default 0 in each slot for ints
        }
        std::cout << "-> Called SIZE Constructor\n";
    }

    // =================================================================
    // Constructor 2: Brace Initialization (std::initializer_list)
    // Triggered by Braces: CustomVector<int> vec{5};
    // =================================================================
    CustomVector(std::initializer_list<T> list) {
        current_size = list.size();
        data = new T[current_size];
        
        // Copy the specific values from the braces into our memory
        std::copy(list.begin(), list.end(), data);
        
        std::cout << "-> Called BRACE (Initializer List) Constructor\n";
    }

    // Standard Destructor for RAII cleanup
    ~CustomVector() {
        delete[] data;
    }

    // Utility methods to display the results
    size_t size() const { return current_size; }
    
    void print() const {
        std::cout << "   Contents: [ ";
        for(size_t i = 0; i < current_size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "]\n";
    }
};

int main() {
    std::cout << "1. Using Parentheses: CustomVector<int> vec1(5);\n";
    // The compiler sees () and looks for a normal constructor.
    // It builds a vector of size 5, filled with 0s.
    CustomVector<int> vec1(5);
    std::cout << "   Size: " << vec1.size() << "\n";
    vec1.print();
    std::cout << "\n";

    std::cout << "2. Using Braces: CustomVector<int> vec2{5};\n";
    // The compiler sees {} and HIJACKS the call to the initializer_list constructor!
    // It builds a vector of size 1, containing the number 5.
    CustomVector<int> vec2{5};
    std::cout << "   Size: " << vec2.size() << "\n";
    vec2.print();
    std::cout << "\n";

    std::cout << "3. Using Braces (Multiple Values): CustomVector<int> vec3{10, 20, 30};\n";
    // The compiler bundles these into the initializer_list constructor.
    CustomVector<int> vec3{10, 20, 30};
    std::cout << "   Size: " << vec3.size() << "\n";
    vec3.print();

    return 0;
}
