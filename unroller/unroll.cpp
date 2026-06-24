#include <iostream>

// 1. The Generic Blueprint (The Recursive Step)
template <int N>
struct Unroller {
    // We pass in an "Action" (usually a lambda function)
    template <typename Action>
    static constexpr void run(Action action) {
        // First, recursively call the Unroller for N - 1
        Unroller<N - 1>::run(action);
        
        // Then, execute the action for the current step
        action(N - 1); 
    }
};

// 2. The Full Specialization (The Base Case / Stop Condition)
template <>
struct Unroller<0> {
    template <typename Action>
    static constexpr void run(Action action) {
        // Do absolutely nothing. This stops the recursion!
    }
};

// 3. The Test
int main() {
    // We define an array
    int data[4] = {10, 20, 30, 40};
int dd[5] = {1,2,3,44,5};
    // We define our "Action" as a C++ Lambda function
    auto print_action = [&](int index) {
        std::cout << "Processing data at index " << index << ": " << data[index] << "\n";
    };

    // 4. THE MAGIC HAPPENS HERE
    std::cout << "Starting compile-time unrolled loop:\n";
    Unroller<4>::run(print_action);

    return 0;
}
