#pragma once
#include "Rectangle.hpp"

class Square final : public Rectangle
{
public:
    explicit Square(double side)
        : Rectangle(side, side) {}
};
