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
#include <iostream>
#include <list>
#define _USE_MATH_DEFINES   // Signal math.h that we would like defines like M_PI
#include <math.h>           // Might come in usefull for cosine functions and stuff like that
#include <vector>
#include "main.h"           // Function declarations and some definitions
#include "drawtools.h"      // contains all you need to draw stuff
#include "Enemy.h" 
#include "Turret.h" 
#include <fstream>
#include <map>

//int map[][];
using namespace std;
std::string keytext;
DrawList drawList;
string filename = "test";
//std::list<Enemy*> enemylist;
map<string, int, int> fieldMap;
// Put your global variables here
vector<Enemy*> enenemyvector;
vector<Turret*> turretvector;
vector<Line*> bulletvector;

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
	raster();
}

//read a the map file
void readFile(string filename) {
	string word;
	ifstream fp;
	fp.open(filename, ios::in);
	while (!fp.eof()) {
		fp >> word;
		if (!fp.eof()) { // prevent last line twice
			//add(word);
		}
	}

	// Close the file
	fp.close();

}

//make a grid for easy acces
void raster() {
	//readFile();
	Color color = { 0.2f, 1, 0.2f };
	int rasterHoogte = windowHeight;
	int rasterBreedte = windowWidth;
	int res =  15;
	float radius = 2.5;
	int seg = 5;
	float varx;
	float vary;
	for (int i = 0; i < (rasterBreedte/res); i++) {
		for (int j = 0; j < (rasterHoogte/res); j++) {
			varx = 20 * i;
			vary = 20 * j;
			PointF posPixel = { varx , vary };
			Circle* dots = new Circle(posPixel, color, radius, seg);
			drawList.push_back(dots);
		}
	}
}

void path() {

}

void makeEnemy() {
	Color color = { 0.2f, 1, 0.2f };
	PointF begin1 = { 30,20 };
	PointF begin2 = { 34, 430 };
	float lind = 2.0;
	float r = 10;
	int seg = 10;
	float speed = 5;
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
	
	float r;
	//number of triganles that need to be drawn
	int seg = 20;
	for (unsigned i = 0; i<enenemyvector.size(); i++) {
		PointF curpos = enenemyvector.at(i)->_current;

		//if the enemy is out of the screen
		if (curpos[0] > windowWidth || curpos[1] > windowHeight) {
			//delete the enemy
			enenemyvector.erase((enenemyvector.begin() + i));
		}

		else {
			if (enenemyvector.at(i)->_health > 0) {
				PointF posEnemy = enenemyvector.at(i)->Move();
				enenemyvector.at(i)->Update(posEnemy);
				r = enenemyvector.at(i)->_health;
				Circle* cirle = new Circle(posEnemy, color, r, seg);
				drawList.push_back(cirle);
				cout << "Enemy id :" << endl;
				cout << enenemyvector.at(i)->_id << endl;
				cout << "Enemy health" << endl;
				cout << enenemyvector.at(i)->_health << endl;
				drawBullets(posEnemy, i);
				Bullet(posEnemy, i);
				//draw the bullet
			}
			else
			{
				//delete the enemy from the vecto list
				enenemyvector.erase((enenemyvector.begin() + i));
			}
		}
	}
}

//draw the to be drawn bullets 
void drawBullets(PointF posEnemy, int j){
		
		Color color = { 0.2f, 1, 0.2f };
		float lind = 2.0;
		int bulletlenght = 4;

		//loop trough all the turrets
		for (unsigned i = 0; i < turretvector.size(); i++) {

			//if turret health is positive ->later function
			if (turretvector.at(i)->_health > 0) {
					float dx =  turretvector.at(i)->_position[0] - posEnemy[0];
					float dy =  turretvector.at(i)->_position[1] - posEnemy[1];
					//caclulate range to enemy
					float rangeToEnemy = sqrt(	pow(dx,2)  + pow(dy,2)	);

				cout << rangeToEnemy << endl;

				//if enemy is in the range
				if (rangeToEnemy < turretvector.at(i)->_range) {
					PointF turPos = turretvector.at(i)->_position;
					//if the turret is not aiming a other target
					int aimingId = turretvector.at(i)->_aiming;

					//if the current turret is locked on to the current enemy
					if (aimingId == enenemyvector.at(j)->_id) {
						//draw bullet to the enemy

						Line* bulletline = new Line{ posEnemy, turretvector.at(i)->_position , color, lind };
						drawList.push_back(bulletline);
						
						bulletvector.push_back(bulletline);
						//update track id of the turret
						turretvector.at(i)->Aim(enenemyvector.at(j)->_id);
					}
					//no enemy in track
					if (aimingId == 0) {
						//get current pos of the first enemy
						PointF posEnemy = enenemyvector.front()->_current;


						Line* bulletline = new Line{ posEnemy, turretvector.at(i)->_position , color, lind };
						drawList.push_back(bulletline);
						
						bulletvector.push_back(bulletline);
						//update track id of the turret
						turretvector.at(i)->Aim(enenemyvector.front()->_id);
					}

					//s^2 ( V_b^2 - V_e^2) + 1s*r*V_e^2*cos(a) - V_e^2*r^2



				}

			}
			//destroy turret
			else {
				
			}
		}
}

void makeTurret(float x,float y) {
	Color color = { 0.2f, 1, 0.2f };
	PointF pos = { x,y };
	int health = 100;
	int upgrade = 0;
	int type = 0;
	int range = 300;
	Turret* tur = new Turret(pos, color, range, health,upgrade,type);
	turretvector.push_back(tur);
}

void drawTurret() {
	for (unsigned i = 0; i < turretvector.size(); i++) {
		Color color = { 0.2f, 0.2f, 0.2f };
		PointF pos = turretvector.at(i)->_position;
		PointF begin2 = { (pos[0] - 20) ,(pos[1]) };
		PointF begin3 = { (pos[0]) , (pos[1] + 40) };
		PointF begin4 = { (pos[0] + 20) , (pos[1]) };
		Sqaure* sq = new Sqaure(pos, begin2, begin3, begin4, color);
		drawList.push_back(sq);
	}
}

void Bullet(PointF posEnemy,int j) {
	for (unsigned i = 0; i < bulletvector.size(); i++) {
		PointF end = bulletvector.at(i)->end();
		//if the bullet end position is the same as the current enemy position eg a hit of the bullet
		if (end[0] == posEnemy[0] && end[1] == posEnemy[1]) {
			//
			enenemyvector.at(j)->Health(-10);
		}
	}
}
//if idle do all the calculations
void idle(int value) {
	raster();
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
	raster();
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