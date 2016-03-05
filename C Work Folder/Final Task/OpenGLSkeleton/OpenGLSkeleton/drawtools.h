////////////////////////////////////////////////////////////
//
// File: drawtools.cpp
// Author: Peter Koek (based on version by Sven Goossens)
// Purpose:
//      Extending the Drawable class to provide a set of drawing tools
//      Provides helper class Point (PointF and PointI) and Color
//      Contains an implementation of the Pixel class,
//      and a skeleton for the Line class
//
///////////////////////////////////////////////////////////

#ifndef DRAWTOOLS_H
#define DRAWTOOLS_H

#include <array>

#include "drawlist.h"
//
// Point template (you can ignore the template part)
// Use PointF for a point with float values
// Use PointI for a point with int values
//

template<typename T>
class Point
{
public:
    // Constructors

    Point() = default;
    Point(const T& x, const T& y)
        : _data({{x, y}})
    { }

    // Convenience accessors x() and y()

    T& x()
    { return _data[0]; }

    const T& x() const
    { return _data[0]; }

    T& y()
    { return _data[1]; }

    const T& y() const
    { return _data[1]; }

    // Indexing operator []

    T& operator[](int i)
    { return _data[i]; }

    const T& operator[](int i) const
    { return _data[i]; }

    // Access to internal storage

    T* data()
    { return _data.data(); }

    const T* data() const
    { return _data.data(); }

private:
    // Internal data
    std::array<T, 2> _data;
};

// 2D Point with integer precision
using PointI = Point<int>;

// 2D Point with floating point precision
using PointF = Point<float>;

//
// Color
//

struct Color
{
public:
    // Constructors
    Color() = default;
    Color(float red, float green, float blue)
        : _data({{red, green, blue}})
    { }

    // Convenience accessors r(), g() and b()

    float& r()
    { return _data[0]; }

    const float& r() const
    { return _data[0]; }

    float& g()
    { return _data[1]; }

    const float& g() const
    { return _data[1]; }

    float& b()
    { return _data[2]; }

    const float& b() const
    { return _data[2]; }

    // Indexing operator []

    float& operator[](int i)
    { return _data[i]; }

    const float& operator[](int i) const
    { return _data[i]; }

    // Access to internal storage

    float* data()
    { return _data.data(); }

    const float* data() const
    { return _data.data(); }

private:
    // Internal data
    std::array<float, 3> _data;
};

//
// Pixel
// Please note that the Pixel class is an extremely inefficient way
// of coloring pixels on the screen.

class Pixel : public Drawable    // inherits from item because its part of a DrawList
{
public:
	// Constructor that accepts a position and a color
    Pixel(const PointF& position, const Color& color);

    // Draw Pixel to the screen
    void draw() const override;

    // Print Pixel in EDIF++ format
	void print() const override;

	// You can add more public members here, if needed

private:
    PointF _position;
    Color _color;

	// You can add more private members here, if needed
};

//
// Line
//

class Line : public Drawable
{
public:
	// constructors. Specify the list of the line, postion, color and width
    Line(const PointF& begin, const PointF& end, 
         const Color& color, float lineWidth);

    const PointF& begin() const;
    const PointF& end() const;

    // Draw Line to the screen
    void draw() const override;

    // Print Line in EDIF++ format
	void print() const override;

	// You can add more public members here, if needed

private:
    PointF _begin;
    PointF _end;
    Color _color;
    float _lineWidth;
	// You can add more private members here, if needed
};

//
// Text
//

class Text : public Drawable
{
public:
    Text(const std::string& str);

    // Draw Line to the screen
    void draw() const override;

    // Print Line in EDIF++ format
    void print() const override;

	// You can add more public members here, if needed

private:
	std::string _str;

	// You can add more private members here, if needed
};

#endif
