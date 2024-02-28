#include <iostream>
#include <map>
#include <vector>
#include "allocator.hpp"
#include "stack.hpp"

int main(){
    std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>>> m;
    m[0] = 1;
    for (size_t i = 1; i != 10; ++i) {
        m[i] = m[i - 1] * i;
    }

    std::cout << "Here are the elements of map: " << std::endl;
    for (auto [k, v] : m) {
        std::cout << k << " " << v << std::endl;
    }
    
    return 0;
}