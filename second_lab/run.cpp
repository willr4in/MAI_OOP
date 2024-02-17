#include <iostream>
#include <string>
#include "include/money.hpp"
#include "src/money.cpp"

int main(){
    Money a {'1','2','4','7','8','2','1'};
    std::cout << "a = ";
    a.print();

    Money b{'1','1','1'};
    std::cout << "b = ";
    b.print();

    Money c(a.add(b));
    std::cout << "c = a + b = ";
    c.print();

    Money d {"0005"};
    std::cout << "d = ";
    d.print();

    d.remove(b);
    std::cout << "d - b = ";
    d.print();
}

