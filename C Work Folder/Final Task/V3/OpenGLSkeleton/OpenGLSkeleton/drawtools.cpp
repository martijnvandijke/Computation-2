////////////////////////////////////////////////////////////
//
// File: drawtools.cpp
// Author: Peter Koek (based on version by Sven Goossens)
// Purpose:
//      Extending the Drawable class to provide a set of drawing tools
//      Contains an implementation of the Pixel class,
//      and a skeleton for the Line class
// edited by Martyn van Dijke
//
///////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string.h>
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
	glDisable(GL_POINTS);
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
	//cout << "test" << endl;
	// To be implemented by you
    // Hint: Look at how Pixel manipules the output stream with manipulators
    // For a detailed reference, look here: http://en.cppreference.com/w/cpp/io/manip
}

void Line::draw() const
{
	//cout << "Lijntjes tekenen" << endl;
	glLineWidth( _lineWidth);
	// dashed lines as  http://www.opengl.org.ru/docs/pg/0204.html
	//glLineStipple(1, 0x3F07);
	//glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	glColor3f(_color[0], _color[1], _color[2]);
	glVertex2fv(_begin.data() );
	glVertex2fv(_end.data() );
	glDisable(GL_LINES);
	glEnd();
	// To be implemented by you
	// Aim for about 10 lines of code
}


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
	glColor3fv(_color.data());
	for (int n = 0; n <= _segments; ++n) {
		float const t = 2 * M_PI * (float)n / (float)_segments;
		glVertex2f(_position.x() + sin(t) * _radius, _position.y() + cos(t) * _radius);
	}
	glDisable(GL_TRIANGLE_FAN);
	glEnd();
}

void Circle::print() const
{
	//cout << "test of cricle " << endl;
	//print function
}

Sqaure::Sqaure(const PointF & begin, const PointF & end, const PointF & begin2, const PointF & end2, const Color & color )
	: _begin{ begin }
	, _end{ end }
	, _end2{end2}
	, _begin2{begin2}
	, _color{ color }
{
	//
}

void Sqaure::draw() const
{
	//draw function
	glBegin(GL_QUADS);
	glColor3fv(_color.data());
	glVertex2f(	_begin.x() ,_begin.y()	);
	glVertex2f( _end.x() , _end.y()	);
	glVertex2f( _begin2.x(), _begin2.y());
	glVertex2f( _end2.x(),  _end2.y());
	glDisable(GL_QUADS);
	glEnd();
}

void Sqaure::print() const
{
	//print fuinction
}




Text::Text(const string string, Color color, PointF Pos)
	: _string{string},
	_color{color},
	_Position{Pos}
{

}

void Text::draw() const
{
	
	//cout << "ga text printen" << endl;
	glColor3f(_color[0], _color[1], _color[2]);
	glRasterPos2f(_Position[0], _Position[1]);
	//cout << _Position[0] <<"  " << _Position[1] << endl;
	string text = _string;
	//cout << text << endl;
	for (char& c : text)
	{	
		//cout << "Ik ga printen"<< c << endl;
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c	);
	}
}

void Text::print() const
{

}
Heart::Heart(Color color, PointF Pos)
	:_color{color},
	_Pos{ Pos }
{

}

void Heart::draw() const
{
	
	// http://mathworld.wolfram.com/HeartCurve.html
	glBegin(GL_LINE_LOOP);
	glVertex2d(_Pos[0], _Pos[1]);
}
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-2, 2, -2, 2);
//	glPointSize(2);
//	glColor3ub(255, 0, 0);  // Color Red
//	glBegin(GL_POINTS);
//	for (float x = -1.139; x <= 1.139; x += 0.001)
//	{
//		float delta = cbrt(x*x) * cbrt(x*x) - 4 * x*x + 4;
//		float y1 = (cbrt(x*x) + sqrt(delta)) / 2;
//		float y2 = (cbrt(x*x) - sqrt(delta)) / 2;
//		glVertex2f(x, y1);
//		glVertex2f(x, y2);
//	}
//	glEnd();
//	glMatrixMode(GL_MODELVIEW);
//}

void Heart::print() const
{

}
//text mode color begin pos end pos
Button::Button(string text, int mode, Color color, PointF begin, PointF end)
	: _color{color},
	_text{text},
	_mode{mode},
	_begin{begin},
	_end{end}
{


}

void Button::draw() const
{

	// Create font:


	//fill sqaure
	if (_mode == 1) {

	}

	Color Textcolor = { 0.375, 0.48828125, 0.54296875 };
	glColor3f(_color[0], _color[1], _color[2]);
	glRasterPos2f(_begin[0], _begin[1]);
	//cout << _Position[0] <<"  " << _Position[1] << endl;
	string text = _text;
	//cout << text << endl;
	for (char& c : text)
	{
		//cout << "Ik ga printen"<< c << endl;
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	}
	
}

void Button::print() const
{

}

void Button::Update()
{
}
