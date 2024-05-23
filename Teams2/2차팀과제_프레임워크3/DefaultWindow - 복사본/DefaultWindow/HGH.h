#pragma once
#define E2I(_enum)              static_cast<int>(_enum)
#define DGREE_TO_RADIAN(degree) (degree*PI/180.f)
#define RADIAN_TO_DEGREE(rad)   (rad*180.f/PI)

template<typename T = float>
struct Vec2
{
    T x;
    T y;

    void operator+=(Vec2<T> _rhs)
    {
        x += _rhs.x;
        y += _rhs.y;
    }
    bool operator== (Vec2<T> _rhs)
    {
        return (x == _rhs.x && y == _rhs.y);
    }
    bool operator!= (Vec2<T> _rhs)
    {
        return !operator==(_rhs);
    }

    Vec2<T> operator-(Vec2<T> _rhs)
    {
        return Vec2<T>{ x - _rhs.x, y - _rhs.y };
    }

    Vec2<T> operator+(Vec2<T> _rhs)
    {
        return Vec2<T>{x + _rhs.x, y + _rhs.y};
    }
    Vec2<T> operator*(T _scale)
    {
        return Vec2<T>{x* _scale, y* _scale};
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


    Vec2<T> Rotate(float _fTheta)
    {
        return Vec2<T>{ this->x * cosf(_fTheta) - this->y * sinf(_fTheta), this->x * sinf(_fTheta) + this->y * cosf(_fTheta) };
    }
};

template<typename T = float>
using Point2    = Vec2<T>;
using Vec2F     = Vec2<float>;
using Point2F   = Vec2<float>;

template<typename T = float>
struct Line2
{
    Point2<T> p1;
    Point2<T> p2;
};

using Line2F = Line2<float>;

#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>