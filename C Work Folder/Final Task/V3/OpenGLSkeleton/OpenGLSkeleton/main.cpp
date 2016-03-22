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
#include <vector>
#include "main.h"           // Function declarations and some definitions
#include "drawtools.h"      // contains all you need to draw stuff
#include "Enemy.h" 
#include "Turret.h" 
#include <list>

using namespace std;
std::string keytext;
DrawList drawList;
//std::list<Enemy*> enemylist;

// Put your global variables here
vector<Enemy*> enenemyvector;
vector<Turret*> turretvector;

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
    
    // E.g. glClearColor(1.0, 0.0, 0.0, 1.0); results in a red background.
    glClearColor(0.003921568627451, 0.502, 0.447, 0.2);               // Set background color to white

    
    // Keep them like this if you don't need fancy options
    glMatrixMode(GL_PROJECTION);    // Next lines will adjust the projection matrix
    glLoadIdentity();               // Reset projection matrix to the identity matrix

    // Set the size of the viewport (drawing grid) in pixels
    // We are looking at the rectangle from (0,0) to (windowWidth,windowHeight)
    gluOrtho2D(0, windowWidth, 0, windowHeight);

    glMatrixMode(GL_MODELVIEW);
	makeTurret(100,200);
	makeEnemy();


}

void makeEnemy() {
	Color color = { 0.2f, 1, 0.2f };
	PointF begin1 = { 30,20 };
	PointF begin2 = { 34, 430 };
	float lind = 2.0;

	float r = 10;
	int seg = 10;
	float speed = 10;
	int health = 20;
	Enemy* en = new Enemy(begin1, begin1, speed, health);
	enenemyvector.push_back(en);
}

void drawEnemy() {
	Color color = { 0.2f, 1, 0.2f };
	//statrt position of the enemy
	PointF begin1 = { 30,20 };
	//position of the turren
	PointF begin2 = { 34, 430 };
	float lind = 2.0;
	float r;
	//number of triganles that need to be drawn
	int seg = 20;
	for (unsigned i = 0; i<enenemyvector.size(); i++) {
		PointF posEnemy = enenemyvector.at(i)->Move();
		enenemyvector.at(i)->Update(posEnemy);
		r = enenemyvector.at(i)->_health;
		Circle* cirle = new Circle(posEnemy, color, r, seg);
		drawList.push_back(cirle);
		Line* bulletline = new Line{ posEnemy, turretvector.at(0)->_position , color, lind };
		drawList.push_back(bulletline);
	}
}

void makeTurret(float x,float y) {
	Color color = { 0.2f, 1, 0.2f };
	PointF pos = { x,y };
	int health = 100;
	int upgrade = 0;
	int type = 0;
	int range = 100;
	Turret* tur = new Turret(pos, color, range, health,upgrade,type);
	turretvector.push_back(tur);
}

void drawTurret() {
	for (unsigned i = 0; i < turretvector.size(); i++) {
		Color color = { 0.2f, 1, 0.2f };
		PointF pos = turretvector.at(i)->_position;
		PointF begin2 = { (pos[0] - 20) ,(pos[1]) };
		PointF begin3 = { (pos[0]) , (pos[1] + 40) };
		PointF begin4 = { (pos[0] + 20) , (pos[1]) };
		Sqaure* sq = new Sqaure(pos, begin2, begin3, begin4, color);
		drawList.push_back(sq);
	}
}

//if idle do all the calculations
void idle(int value) {
	
	//always make a turrent before the enemy
	//makeTurret();
	//draw the turret's
	drawTurret();

	//make a new enemy
	//makeEnemy();
	//draw the ennemy
	drawEnemy();

	//make a new turret
	
	


	//cal the display function -> draw everything 
	glutPostRedisplay();
	//cal this function agains
	glutTimerFunc(160, idle, 100);
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
void reshape(int w, int h) 
{    
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
}



//---------------------------------------------------------------------------
// void display(void)
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);   // clear the backbuffer

	drawtext(keytext, 100, 100);
	for (Drawable* drawable : drawList){ 
		drawable->draw(); 
		
	}
	
    // Visualize the drawing commands
    glFlush();            // Execute all commands waiting to be executed
    glutSwapBuffers();    // Swap the backbuffer and frontbuffer
	drawList.clear();
}

void keyfunc(unsigned char key, int x, int y) {
	if (key == 't') {
		cout << "jow ik maak een turret aan" << endl;
		makeTurret(x,y);
	}
	if (key == 'e') {
		cout << "jow ik maak een enemy aan" << endl;
		makeEnemy();
	}

	char c = key;
	keytext = string{ c } +", " + to_string(x) + ", " + to_string(y);
	
	//cout << "jow ik heb characters" << endl;
	//drawtext(keytext, x, y);
	//glutPostRedisplay();
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