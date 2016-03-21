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

#define _USE_MATH_DEFINES   // Signal math.h that we would like defines like M_PI
#include <math.h>           // Might come in usefull for cosine functions and stuff like that


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
	cout << "test" << endl;
	// To be implemented by you
    // Hint: Look at how Pixel manipules the output stream with manipulators
    // For a detailed reference, look here: http://en.cppreference.com/w/cpp/io/manip
}

void Line::draw() const
{
	cout << "test222" << endl;
	glLineWidth( _lineWidth);
	glBegin(GL_LINES);
	glColor3f(_color[0], _color[1], _color[2]);
	glVertex2fv(_begin.data() );
	glVertex2fv(_end.data() );
	glEnd();
	// To be implemented by you
	// Aim for about 10 lines of code
}

//
// Text
//

// Implement the Text class here

//Cirlce::Circle(const PointF& pos, const Color& color, float r, float segments)
//	: _pos{ pos }
//	, _color{ color }
//	, _radius{ r }
//	, _sharpnes{ segments}
//{
//	//test
//}

//
// Cirlce
//
//Circle::Circle(const PointF& pos, const Color& color, float r, float segments);
//	:_pos{ pos }
//	, _color{ color }
//	, _r{ r }
//	, _segments{ segments}
//{
//	// To be implemented by you
//}
//
//const PointF & Circle::pos() const
//{
//	return _pos;
//}
//	//
//void Circle::draw() const
//{
//	glBegin(GL_TRIANGLE_FAN);
//	glVertex2f(x, y);
//	glColor3f(color[0], color[1], color[2]);
//	for (int n = 0; n <= _segments; ++n) {
//		float const t = 2 * M_PI * (float)n / (float)_segments;
//		glVertex2f(x + sin(t) * r, y + cos(t) * r);
//	}
//	glEnd();
//
//}
//
//void Circle::print() const
//{
//	//to do
//}

Circle::Circle(const PointF& position, const Color& color, float radius, int segments)
	: _position{ position }
	, _color{ color }
	, _radius{ radius }
	, _segments{ segments }

{

}

void Circle::draw() const
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(_position.x() , _position.y() );
	//glColor3fv(_color.data());
	for (int n = 0; n <= _segments; ++n) {
		float const t = 2 * M_PI * (float)n / (float)_segments;
		glVertex2f(_position.x() + sin(t) * _radius, _position.y() + cos(t) * _radius);
	}
	glEnd();
}

void Circle::print() const
{
	cout << "test of cricle " << endl;
	//print function
}
