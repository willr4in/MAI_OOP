#pragma once

#include <cmath>
#include <iostream>
#include "../figures/Point.hpp"

class Figure {
protected:
    Figure() = default;

public:
    virtual ~Figure() = default;

    virtual Point calculate_geometric_center() const = 0;
    virtual double calculate_perimeter() const = 0;
    virtual double calculate_area() const = 0;

    virtual operator double() const = 0;
};

