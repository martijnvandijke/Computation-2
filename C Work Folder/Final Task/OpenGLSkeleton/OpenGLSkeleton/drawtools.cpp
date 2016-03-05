////////////////////////////////////////////////////////////
//
// File: drawtools.cpp
// Author: Peter Koek (based on version by Sven Goossens)
// Purpose:
//      Extending the Drawable class to provide a set of drawing tools
//      Contains an implementation of the Pixel class,
//      and a skeleton for the Line class
//
///////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>

#include "glut.h"
#include "drawtools.h"

using namespace std;

//
// Pixel
//

Pixel::Pixel(const PointF& position, const Color& color)
    : _position{ position }
    , _color{ color }
{ }

void Pixel::draw() const
{
	glBegin(GL_POINTS); // Start drawing mode

        // Set color
	    glColor3fv(_color.data());

        // Draw the pixel at _position
        glVertex2fv(_position.data());

	glEnd();
}

void Pixel::print() const
{
    cout << ".pixel"
        << fixed // Fixed precision (decimals)
        << setprecision(0) << " " << _position[0] << " " << _position[1]
        << setprecision(5) << " " << _color[0] << " " << _color[1] << " " << _color[2]
        << endl;
}

//
// Line
//

Line::Line(const PointF& begin, const PointF& end,
           const Color& color, float lineWidth)
    : _begin{ begin }
    , _end{ end }
    , _color{ color }
    , _lineWidth{ lineWidth }
{
	// To be implemented by you
}

const PointF& Line::begin() const
{
    return _begin;
}

const PointF& Line::end() const
{
    return _end;
}

void Line::print() const
{
	// To be implemented by you
    // Hint: Look at how Pixel manipules the output stream with manipulators
    // For a detailed reference, look here: http://en.cppreference.com/w/cpp/io/manip
}

void Line::draw() const
{
	// To be implemented by you
	// Aim for about 10 lines of code
}

//
// Text
//

// Implement the Text class here
