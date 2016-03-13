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



using namespace std;

// Put your global variables here
std::string keytext;

DrawList drawList;

int number_enemys = 0;
int health[] = {20,40,50};
int posx[] = { 40,500,30 };
int posy[] = {800,60,20};
int speed[];

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
	int x = 100;
	int y = 100;
	glutKeyboardFunc(keyfunc);


    // Example Timer functions
    // You might want to remove these after you are done testing with them
    glutTimerFunc(1000, alarm, 112);
    glutTimerFunc(1500, alarm, 1);
    glutTimerFunc(2000, alarm, 2);

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
	PointF position = { 512, 384 }; 
	Color color = { 0.2f, 1, 0.2f };
	Pixel* pixel = new Pixel{ position, color };
	drawList.push_back(pixel);
	pixel->print();
	float kleurtjes[3] = { 0, 0.5, 0.7 };
	//float point2[2] = { 200, 250 };
	float point3[2] = { 400, 500 };
	//float point1 = 200;
	float point12 = 300;
	float linewidth = 2;

	float point1[2] = { 400,200 };
	float point2[2] = { 30, 100 };
	float colors[3] = { 1,0.6,0.8 };
	float line_width = 2.5;
	Lines(point1, point2, colors, line_width);
	glutPostRedisplay();
	Line* newline = new Line(point2, point3, kleurtjes, linewidth);
	newline->draw();
}

void idle( int value) {
	
	float point1[2] = { 400,200 };
	float point2[2] = { 30, 100 };
	float colors[3] = { 1,0.6,0.8 };
	float line_width = 2.5;
	Lines(point1, point2, colors, line_width);

	float point3[2] = { 500,400 };
	float point4[2] = { 800, 900 };
	Lines(point3, point4, colors, line_width);

	float point5[2] = { 700,400 };
	float point6[2] = { 300, 900 };

	Lines(point5, point6, colors, line_width);

	circle(10, 30, 20,  12);
	
	Enemys(0, 3);

	//glFlush();
	//glFlush();            // Execute all commands waiting to be executed
	glutSwapBuffers();
	glutTimerFunc(160, idle , 10);
}


void Enemys(int type, int number) {

	//draw enemys if type 1
	if (type == 0) {
		//draw number of eneyms on screen
		for (int i = 0; i < number; i++) {
			//if the enemy still has health
			if (health[i] != 0) {
				
				//draw the enemy
				circle(posx[i],posy[i], 20, 12);
				

			}
			//delete the helath on that plcae
			/*else{
				health[i] = health[i + 1];*/

		}

	}

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

void keyfunc(unsigned char key, int x, int y){
	char c = key; 
	keytext = string{ c } +", " + to_string(x) + ", " + to_string(y);
	glutPostRedisplay();
	//cout << "jow ik heb characters" << endl;
	drawtext(keytext, x, y);
}

void drawtext(std::string keytext, int x, int y){

	//cout << "jow ik ga ze uitrpinten" << endl;
	glRasterPos2f(100, 100);
	glColor3f(0, 0, 0);
	
	for (char& c : keytext)
	{
		//cout << c << endl;
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	}

}
//
//void drawLine(const PointF& begin, const PointF& end, const Color& color, float lineWidth){
//	glLineWidth(10);
//	glBegin(GL_LINES);
//	glColor3f(color[0], color[1], color[2]);
//	glVertex2fv( _begin);
//	glVertex2fv( _end);
//	glEnd();
//	
//}

void circle(float x, float y, float r, int segments)
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (int n = 0; n <= segments; ++n) {
		float const t = 2 * M_PI * (float)n / (float)segments;
		glVertex2f(x + sin(t) * r, y + cos(t) * r);
	}
	glEnd();
}
void Lines(float begin_line[2], float end_line[2], float color[3], float line_width) {
	//glClear(GL_COLOR_BUFFER_BIT);
	cout << "Ik ga lijntjes tekenen" << endl;
	glLineWidth(line_width);
	glBegin(GL_LINES);
	glColor3f(color[0], color[1], color[2]);
	glVertex2fv(begin_line);
	glVertex2fv(end_line);

	glEnd();
	//glFlush();
	//glFlush();            // Execute all commands waiting to be executed
	//glutSwapBuffers();
	//glutPostRedisplay();
	
	//glFlush();
	//glutSwapBuffers();
}





//---------------------------------------------------------------------------
// void display(void)
// The main display callback. This callback is called when the screen has
// to be redrawn. This is when:
// - The screen first becomes active
// - The screen is resized
// - You call glutPostRedisplay()
void display()
{
	cout << "Going to redraw the screen" << endl;
    glClear(GL_COLOR_BUFFER_BIT);   // clear the backbuffer
    glBegin(GL_POINTS);             // Start a new drawing block for drawing points

        // Draw points here
        // The point (0,0) corresponds to the lower left corner.

        //// The following lines will draw the point (100, 200) in red
        //glColor3f(1.0, 0.0, 0.0);   // Set color
        //glVertex2f(100, 200);       // Set position

        //// The following lines will draw the point (200, 400) in blue
        //// Alternative approach to the above:
        //Color color = { 0.0f, 0.0f, 1.0f }; // A color (see drawtools.h)
        //glColor3fv(color.data());           // Set color from array
        //PointF point = { 200, 400 };        // A two dimensional point (see drawtools.h)
        //glVertex2fv(point.data());          // Set position from array

    glEnd(); // End of the drawing block
	drawtext(keytext, 100, 100);

	//float point1[2] = { 400,200 };
	//float point2[2] = { 30, 100 };
	//float colors[3] = { 1, .6,0.8 };
	//float line_width = 2.5;

	//Lines(point1, point2, colors, line_width);

    // Visualize the drawing commands
    glFlush();            // Execute all commands waiting to be executed
    glutSwapBuffers();    // Swap the backbuffer and frontbuffer



	/*for (Drawable* drawable : drawList){ 
		drawable->draw(); 
	}*/

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
	//if the screen is idle call the idle void
	//glutIdleFunc(idle);

	glutTimerFunc(10, idle, 10);

    glutMainLoop();


    return EXIT_SUCCESS;
}