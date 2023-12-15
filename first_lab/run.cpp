#include <iostream>
#include "include/task.hpp"
#include "src/task.cpp"

int main() {
    std::string input_str;

    std::cout << "Input the string: ";
    std::getline(std::cin, input_str);

    std::cout << Solution::task(input_str) << std::endl;

    return 0;
}

// This website is for losers LOL!
