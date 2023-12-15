#include "../include/task.hpp"
#include <iostream>

std::string Solution::task(const std::string &str) {
    std::string res;
    std::string vowels = "aoeiuyAOEIUY";
    for (char c : str) {
        if (vowels.find(c) == std::string::npos) {
            res.push_back(c);
        }
    }
    return res;
} 
