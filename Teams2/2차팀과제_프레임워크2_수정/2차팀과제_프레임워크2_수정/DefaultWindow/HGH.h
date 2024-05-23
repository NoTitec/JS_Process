#pragma once
#include "string"

template<typename T = float>
struct Vec2
{
    T x;
    T y;

    void operator+=(Vec2 _rhs)
    {
        x += _rhs.x;
        y += _rhs.y;
    }
    bool operator== (Vec2 _rhs)
    {
        return (x == _rhs.x && y == _rhs.y);
    }
    bool operator!= (Vec2 _rhs)
    {
        return !operator==(_rhs);
    }
    T Get_Length()
    {
        return sqrt(x * x + y * y);
    }
    void Normalize()
    {
        x /= Get_Length();
        y /= Get_Length();
    }
};

template<typename T = float>
using Point = Vec2<T>;
using Vec2F = Vec2<float>;
using Point2F = Vec2<float>;

template<typename T = float>
struct Line2
{
    Point<T> p1;
    Point<T> p2;
};

using Line2F = Line2<float>;

#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#include <iostream>