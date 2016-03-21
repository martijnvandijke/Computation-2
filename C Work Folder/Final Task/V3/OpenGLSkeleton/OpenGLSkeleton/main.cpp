////////////////////////////////////////////////////////////
//
// File: main.cpp
// Author: Peter Koek (based on version by Sven Goossens)
// Purpose:
//      A skeleton for the final assignment
//      Without modifications, this should draw 2 pixels on the screen
//
///////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "glut.h"           // glut header file. Never include glut before stdlib.h!

#define _USE_MATH_DEFINES   // Signal math.h that we would like defines like M_PI
#include <math.h>           // Might come in usefull for cosine functions and stuff like that

#include "main.h"           // Function declarations and some definitions
#include "drawtools.h"      // contains all you need to draw stuff
#include "Enemy.h" 

using namespace std;
std::string keytext;
DrawList drawList;

// Put your global variables here


//---------------------------------------------------------------------------
// void init(void)
// This function is called when glut is initialized. Use it to initialize
// variables and setup things that have to be done BEFORE the actual
// picture is drawn.

void init()
{
    // Create a display window
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);    // Double buffering, RGB format
    glutInitWindowSize(windowWidth, windowHeight);  // 1024 x 500 pixel window
    glutInitWindowPosition(0,0);                    // Window appears in the top-left corner of the screen
    glutCreateWindow(windowTitle);                  // Create window with title

    // Register callbacks
    glutDisplayFunc(display);                       // Main display function
    glutReshapeFunc(reshape);                       // Reshape function, called when the window resizes
	glutKeyboardFunc(keyfunc);

    // Example Timer functions
    // You might want to remove these after you are done testing with them
    glutTimerFunc(1000, alarm, 112);
    //glutTimerFunc(1500, alarm, 1);
    //glutTimerFunc(2000, alarm, 2);

    // Set the background color.
    // The color is in the (red, green, blue, alpha) format (RGBA)
    // Color values range from 0.0f to 1.0f.
    // E.g. glClearColor(1.0, 0.0, 0.0, 1.0); results in a red background.
    glClearColor(1.0, 1.0, 1.0, 1.0);               // Set background color to white

    // The following funtions setup the view of the screen.
    // OpenGL actually creates a 3D world, which is displayed trough a
    // viewport (the glut window). The way pixels are projected onto
    // this viewport is setup here.
    // Keep them like this if you don't need fancy options
    glMatrixMode(GL_PROJECTION);    // Next lines will adjust the projection matrix
    glLoadIdentity();               // Reset projection matrix to the identity matrix

    // Set the size of the viewport (drawing grid) in pixels
    // We are looking at the rectangle from (0,0) to (windowWidth,windowHeight)
    gluOrtho2D(0, windowWidth, 0, windowHeight);

    glMatrixMode(GL_MODELVIEW);
	//PointF position = { 512, 384 };
	//Color color = { 0.2f, 1, 0.2f };
	//Pixel* pixel = new Pixel{ position, color };
	//drawList.push_back(pixel);
	//pixel->draw();

	//PointF begin1 = { 30,400 };
	//PointF begin2 = { 34, 430 };
	//PointF begin3 = { 45,410 };
	//PointF begin4 = { 48, 412 };
	//float lind = 2.0;
	////Line* line = new Line{ begin1, begin2, color ,lind };
	////drawList.push_back(line);
	//float r = 10;
	//int seg = 10;
	////Circle* cirle = new Circle(begin1, color, r, seg);
	////drawList.push_back(cirle);
	//Sqaure* sq = new Sqaure(begin1, begin2,begin3,begin4, color);
	//drawList.push_back(sq);
	//float speed = 200;
	//int health = 100;
	//Enemy* en = new Enemy(begin1, speed, health );
	//PointF posEnemy = en->Move();
	//Circle* cirle = new Circle(posEnemy, color, r, seg);
	//drawList.push_back(cirle);
	//PointF bullet = { posEnemy.x()	,posEnemy.y() };
	//Line* bulletline = new Line{ bullet, begin2, color, lind };
	//drawList.push_back(bulletline);
	//glLineStipple(110,1400);

}

//if idle do all the calculations
void idle(int value) {
	PointF position = { 512, 384 };
	Color color = { 0.2f, 1, 0.2f };
	Pixel* pixel = new Pixel{ position, color };
	drawList.push_back(pixel);
	pixel->draw();

	PointF begin1 = { 30,400 };
	PointF begin2 = { 34, 430 };
	PointF begin3 = { 45,410 };
	PointF begin4 = { 48, 412 };
	float lind = 2.0;
	//Line* line = new Line{ begin1, begin2, color ,lind };
	//drawList.push_back(line);
	float r = 10;
	int seg = 10;
	//Circle* cirle = new Circle(begin1, color, r, seg);
	//drawList.push_back(cirle);
	Sqaure* sq = new Sqaure(begin1, begin2, begin3, begin4, color);
	drawList.push_back(sq);
	float speed = 200;
	int health = 100;
	Enemy* en = new Enemy(begin1, speed, health);
	PointF posEnemy = en->Move();
	Circle* cirle = new Circle(posEnemy, color, r, seg);
	drawList.push_back(cirle);
	PointF bullet = { posEnemy.x()	,posEnemy.y() };
	Line* bulletline = new Line{ bullet, begin2, color, lind };
	drawList.push_back(bulletline);
	begin1 = { posEnemy[0]	,posEnemy.y() };
	//Enemy* en = new Enemy(begin1, speed, health);
	glutPostRedisplay();
	glutTimerFunc(160, idle, 10);
}

//---------------------------------------------------------------------------
// void alarm(int alarmnumber)
// Demonstration of a timer callback. alarmnumber is used to distinguish
// between different timers.

void alarm(int alarmNumber)
{
    if(alarmNumber == 112) {
        cout << "Ring Ring!!! This was alarm 112!" << endl;
        cout << "Next alarm will ring in 100 ms." << endl;

        // Register another timer with a different number that triggers after 100 ms
        glutTimerFunc(100, alarm, 1337);
    } else {
        cout << "Ring Ring!!! Alarm with alarmnumber " << alarmNumber << " called!" << endl;
    }
}

//---------------------------------------------------------------------------
// void reshape(int w, int h)
// Handle window resizing (reshaping) events
// The reshape callback is called when the window is resized or moved
// In the current implementation, the drawing grid is extended or truncated 
// when the window is reshaped

void reshape(int w, int h) 
{    
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
}

//latter refrence use
//for (auto it = drawList.begin(); it != drawList.end(); /* nothing */) {
//	if (/* condition */) {
//		it = drawList.erase(it); // Erase returns the next iterator } else { ++it; // Increment the iterator } }
//


//---------------------------------------------------------------------------
// void display(void)
// The main display callback. This callback is called when the screen has
// to be redrawn. This is when:
// - The screen first becomes active
// - The screen is resized
// - You call glutPostRedisplay()

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);   // clear the backbuffer
    //glBegin(GL_POINTS);             // Start a new drawing block for drawing points

    //    // Draw points here
    //    // The point (0,0) corresponds to the lower left corner.

    //    // The following lines will draw the point (100, 200) in red
    //    glColor3f(1.0, 0.0, 0.0);   // Set color
    //    glVertex2f(100, 200);       // Set position

    //    // The following lines will draw the point (200, 400) in blue
    //    // Alternative approach to the above:
    //    Color color = { 0.0f, 0.0f, 1.0f }; // A color (see drawtools.h)
    //    glColor3fv(color.data());           // Set color from array
    //    PointF point = { 200, 400 };        // A two dimensional point (see drawtools.h)
    //    glVertex2fv(point.data());          // Set position from array
		
    //glEnd(); // End of the drawing block
	drawtext(keytext, 100, 100);
	for (Drawable* drawable : drawList){ 
		drawable->draw(); 
		
	}
	
    // Visualize the drawing commands
    glFlush();            // Execute all commands waiting to be executed
    glutSwapBuffers();    // Swap the backbuffer and frontbuffer
}

void keyfunc(unsigned char key, int x, int y) {
	char c = key;
	keytext = string{ c } +", " + to_string(x) + ", " + to_string(y);
	
	//cout << "jow ik heb characters" << endl;
	drawtext(keytext, x, y);
	glutPostRedisplay();
}

void drawtext(std::string keytext, int x, int y) {

	//cout << "jow ik ga ze uitrpinten" << endl;
	glRasterPos2f(100, 100);
	glColor3f(0, 0, 0);

	for (char& c : keytext)
	{
		//cout << c << endl;
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	}

}


//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    // Inialize GLUT
    glutInit(&argc, argv);

    // Initialize your program
    init();

    // Enter the main application loop
    // While in the main loop, your registered callbacks will be called
    cout << "Starting GLUT main loop..." << endl;
	glutTimerFunc(10, idle, 10);
    glutMainLoop();

    return EXIT_SUCCESS;
}