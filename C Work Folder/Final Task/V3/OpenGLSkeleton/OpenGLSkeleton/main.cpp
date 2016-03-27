// Made by Martyn van Dijke
// Student number : 087668
// Build date :
// Version : 
// Main file
///////////////////////////////

#include <iostream>
#include <string>
#include "glut.h"           // glut header file. Never include glut before stdlib.h!
#include <iostream>
#include <list>
#define _USE_MATH_DEFINES   // Signal math.h that we would like defines like M_PI
#include <math.h>           // Might come in usefull for cosine functions and stuff like that
#include <vector>			//get the vector dll's
#include "main.h"           // Function declarations and some definitions
#include "drawtools.h"      // contains all you need to draw stuff
#include "Enemy.h"			//get the enemys class
#include "Turret.h"			//get the turret class
#include "FiredBullet.h"	//get the bulelt class
#include <fstream>	

#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
//#include <vld.h> 
#include <crtdbg.h>

//global variables and defiinitions
using namespace std;
std::string keytext;
DrawList drawList;
string filename = "test";
int PlayerHealth = 100;	//	player health
int PlayerScore = 0;	// player score
string MapName;		//map name 
const int mapSizex = 100;	//map size in x direction
const int mapSizey = 100;	//map size in y direction
char Map[mapSizex][mapSizey];	//map data
//vectors for more easy acces then list and more flexibel :)
vector<Enemy*> enenemyvector;	//vector contains all the enemey
vector<Turret*> turretvector;	//vector contains all the turrets
vector<FiredBullet*> bulletvector; //vector containing all the bullets that have been fired and are still live
int start = 0;

//only excuted once
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

    // E.g. glClearColor(1.0, 0.0, 0.0, 1.0); results in a red background.
    glClearColor(0.003921568627451, 0.502, 0.447, 0.2);               // Set background color to white 
    // Keep them like this if you don't need fancy options
    glMatrixMode(GL_PROJECTION);    // Next lines will adjust the projection matrix
    glLoadIdentity();               // Reset projection matrix to the identity matrix
    // Set the size of the viewport (drawing grid) in pixels
    // We are looking at the rectangle from (0,0) to (windowWidth,windowHeight)
    gluOrtho2D(0, windowWidth, 0, windowHeight);
    glMatrixMode(GL_MODELVIEW);
	makeTurret(100,300);
	makeEnemy();
	raster();
}

//read the map file from a .txt file
void readFile(string filename) {
	string word;
	ifstream fp;
	MapName = filename;
	int CountLines = 0;
	filename = "test.txt";
	fp.open(filename); // , ios::in);
	if (fp.fail()) {
		cout << "Erro parsing the file \n Please try again" << endl;
		return;
	}

	while (	getline(fp, word)){
		//no map has yet been loaded, load the map name

		//count the "y" direction
		CountLines++;
		for (unsigned i = 0; i < word.size(); i++) {
			//get char at place in string
			char c = (word.at(i));
			//store char in the map
			Map[i][(CountLines - 1)] = c;

		}
	}

	// Close the file
	fp.close();

}


//make a grid 
void raster() {
	Color color = { 0.2f, 1, 0.2f };
	int rasterHoogte = windowHeight;
	int rasterBreedte = windowWidth;
	int res =  15;
	float radius = 2.5;
	int seg = 5;
	float varx;
	float vary;

	for (int i = 0; i < (rasterBreedte/res); i++) {
		for (int j = 0; j < ((rasterHoogte)/res); j++) {
			
			varx = 20 * i;
			vary = 20 * j;
			//make a grid if the width still has 200 pixels
			if ((windowWidth - 100) > varx) {
				PointF posPixel = { varx , vary };
				Circle* dots = new Circle(posPixel, color, radius, seg);
				drawList.push_back(dots);
			}
			else {
				continue;
			}
		}
	}

	//draw the grid
	path();
}

//draw the path from the map file
void path() {
	for (int i = 0; i < mapSizex; i++) {
		for (int j = 0; j < mapSizey; j++) {
			float x = i*20;
			float y = j*20;

			if (Map[i][j] == '/') { 
				//draw the path where enemy's walk
				Color color = { 0.2f, 1, 0.2f };
				PointF begin1 = { x,y };
				PointF begin2 = { (x),(y+20) };
				PointF begin3 = { (x-20),(y+20) };
				PointF begin4 = { (x - 20), (y) };
				Sqaure* sq = new Sqaure(begin1, begin2, begin3, begin4, color);
				drawList.push_back(sq);
			}
			//path where building is allowed
			if (Map[i][j] == '*') {
				//draw the building site
				Color color = { 0.4f, 0.4f, 0.4f };
				PointF begin1 = { x,y };
				PointF begin2 = { (x),(y + 20) };
				PointF begin3 = { (x - 20),(y + 20) };
				PointF begin4 = { (x - 20), (y) };
				Sqaure* sq = new Sqaure(begin1, begin2, begin3, begin4, color);
				drawList.push_back(sq);
			}
			//end point of the map
			if (Map[i][j] == 'E') {
				//draw the end map
				Color color = { 1.0f, 0.4f, 0.4f };
				PointF begin1 = { x,y };
				PointF begin2 = { (x),(y + 20) };
				PointF begin3 = { (x - 20),(y + 20) };
				PointF begin4 = { (x - 20), (y) };
				Sqaure* sq = new Sqaure(begin1, begin2, begin3, begin4, color);
				drawList.push_back(sq);
			}
			//if the map data contains nothing special
			else {
				continue;
			}
		}
	}

	
}

//make a new enemey on the stack
void makeEnemy() {
	Color color = { 0.2f, 0.1f, 0.8f };
	PointF begin1 = { 30,40 };
	PointF begin2 = { 0, 0 };
	float lind = 2.0;
	float r = 10;
	int seg = 10;
	float speed = 5;
	int health = 20;
	Enemy* en = new Enemy(begin1, begin1, speed, health);
	enenemyvector.push_back(en);
}
//draw the enemy's + make alogirthm
void drawEnemy() {
	Color color = { 0.2f, 0.1f, 0.8f };
	float r;
	//number of triganles that need to be drawn
	int seg = 20;
	for (unsigned i = 0; i<enenemyvector.size(); i++) {
		PointF curpos = enenemyvector.at(i)->_current;

		//if the enemy is out of the screen
		if (curpos[0] > windowWidth || curpos[1] > windowHeight) {
			//delete the enemy
			delete enenemyvector.at(i);
			cout << "Deleted an enemy" << endl;
			//delete the enemy from the enemy vector
			enenemyvector.erase((enenemyvector.begin() + i));
		}
		//enemy is still in the screen
		else {
			PointF curpos = enenemyvector.at(i)->_current;

			//decrease the enemy health 
			for (unsigned j = 0; j < bulletvector.size(); j++) {
				PointF Bullet = bulletvector.at(j)->_current;

				//bullet and enemy are at the same poition
				if (Bullet[0] == curpos[0] && Bullet[1] == curpos[1]) {
					enenemyvector.at(i)->Health(10);;
					cout << "Damaged an enemy" << endl;
				}

			}
			//walk algorithm is good but could do better
			if (enenemyvector.at(i)->_health > 0) {
				int curx = curpos[0] /20;
				int cury = curpos[1] / 20;
				cout << curx << cury << endl;
				// get the map character that is 20 pixels further
				char nextCharXplus = Map[(curx+1)][cury];
				char nextCharYplus = Map[curx][(cury + 1)];
				char nextCharXmin =	Map[(curx - 1)][cury];
				char nextCharYmin = Map[curx][(cury - 1)];

				//if the enemy is at the end of the defensen
				if (Map[(curx)][cury] == 'E') {
					//decrease the player health
					PlayerHealth = PlayerHealth - 10;
					//delete the enemy
					delete enenemyvector.at(i);
					//delete the enemy from the enemy vector
					enenemyvector.erase((enenemyvector.begin() + i));
					continue;
				}
				//once the end line is insight
				if (Map[(curx + 2)][cury] == 'E') {
					PointF posEnemy = enenemyvector.at(i)->Move(1, 0);
					cout << "Moving enemy right" << endl;
					enenemyvector.at(i)->Update(posEnemy);
					r = enenemyvector.at(i)->_health;
					Circle* cirle = new Circle(posEnemy, color, r, seg);
					drawList.push_back(cirle);
					drawBullets(posEnemy, i);
					//Bullet(posEnemy, i);
					continue;
				}
				//once the end line is insight
				if (nextCharXplus == 'E') {
					PointF posEnemy = enenemyvector.at(i)->Move(1, 0);
					enenemyvector.at(i)->Update(posEnemy);
					r = enenemyvector.at(i)->_health;
					Circle* cirle = new Circle(posEnemy, color, r, seg);
					drawList.push_back(cirle);
					drawBullets(posEnemy, i);
					//Bullet(posEnemy, i);
					//set = 1;
					//enenemyvector.
					continue;
				}
				// move 20 y pixels right
				if (nextCharYplus == '/' && Map[(curx)][(cury +2)] ) {
					PointF posEnemy = enenemyvector.at(i)->Move(0,1);
					//cout << "Moving enemy up" << endl;
					enenemyvector.at(i)->Update(posEnemy);
					r = enenemyvector.at(i)->_health;
					Circle* cirle = new Circle(posEnemy, color, r, seg);
					drawList.push_back(cirle);
					drawBullets(posEnemy, i);
					//Bullet(posEnemy, i);
					//set = 1;
					continue;
				}
				// move 20 x pixels rght
				if (nextCharXplus == '/' && Map[(curx + 2)][cury]== '/'	) {
					
					PointF posEnemy = enenemyvector.at(i)->Move(1, 0);
					//cout << "Moving enemy right" << endl;
					enenemyvector.at(i)->Update(posEnemy);
					r = enenemyvector.at(i)->_health;
					Circle* cirle = new Circle(posEnemy, color, r, seg);
					drawList.push_back(cirle);
					drawBullets(posEnemy, i);
					//Bullet(posEnemy, i);
					continue;
				}
				//move 20 pixels down
				if (nextCharYmin == '/' && Map[curx][(cury - 2)] == '/'  ) {
					//if(	set == 1 ){}
					PointF posEnemy = enenemyvector.at(i)->Move(0, -1);
					//cout << "Moving enemy down" << endl;
					enenemyvector.at(i)->Update(posEnemy);
					r = enenemyvector.at(i)->_health;
					Circle* cirle = new Circle(posEnemy, color, r, seg);
					drawList.push_back(cirle);
					drawBullets(posEnemy, i);
					//Bullet(posEnemy, i);
					//set = 1;
					continue;
				}
				//move 20 pixels left
				if (nextCharXmin == '/') {
					PointF posEnemy = enenemyvector.at(i)->Move(-1, 0);
					//cout << "Moving enemy left" << endl;
					enenemyvector.at(i)->Update(posEnemy);
					r = enenemyvector.at(i)->_health;
					Circle* cirle = new Circle(posEnemy, color, r, seg);
					drawList.push_back(cirle);
					drawBullets(posEnemy, i);
					//Bullet(posEnemy, i);
					
					continue;
				}
				else {
					cout << "error" << endl;
					cout << nextCharXplus << nextCharYplus << nextCharXmin << nextCharYmin << endl;
					cout << curx << "  " << cury << endl;
					//set = 0;
					continue;
 				}


			}
			else	//the enemy has zerp health
			{
					cout << "Deleted an enenemy" << endl;
					//delete the enemy
					delete enenemyvector.at(i);
					//delete the enemy from the enemy vector
					enenemyvector.erase((enenemyvector.begin() + i));
			}
		}
	}
}

//caclulate the interscet point of the bullet to be fired and the enenemy ->nees some debugging
void drawBullets(PointF posEnemy, int j){
		//initilize functions
		Color color = { 0.9f, 0.9f, 0.9f };
		float lind = 2.0;
		int bulletlenght = 4;

		//loop trough all the turrets
		for (unsigned i = 0; i < turretvector.size(); i++) {

			//if turret health is positive ->later function
			if (turretvector.at(i)->_health > 0) {
					//get the distance between the turret and enemy
					//float dx =  turretvector.at(i)->_position[0] - posEnemy[0];
					//float dy =  turretvector.at(i)->_position[1] - posEnemy[1];
					PointF posTurret = turretvector.at(i)->_position;
					float dy = abs(posEnemy[1] - posTurret[1]);
					float dx = abs(posEnemy[0] - posTurret[0]);
					//caclulate range to enemy
					float rangeToEnemy = sqrt(	pow(dx,2)  + pow(dy,2)	);
					//cout << rangeToEnemy << endl;
					//if enemy is in the range
					if (rangeToEnemy < turretvector.at(i)->_range) {
						cout << "Enemy is in range" << endl;
						//get position of the turret
						PointF turPos = turretvector.at(i)->_position;
						//get the aiming id of the turret
						int aimingId = turretvector.at(i)->_aiming;
						//s^2 ( V_b^2 - V_e^2) + 1s*r*V_e^2*cos(a) - V_e^2*r^2
						//if the current turret is locked on to the current enemy
						//if (aimingId == enenemyvector.at(j)->_id) {
							
							int bulletSpeed = turretvector.at(i)->_bulletSpeed;
							int EnemeySpeed = enenemyvector.at(j)->_speed;
							cout << "abs dx ,dy" << endl;
							cout << dx << "   "<< dy << endl;
							//calulate the anlge between the enemy and the turret
							float alfa = atan((dy/dx));
							cout <<"alfa: " << alfa << endl;

//							cout << cos(alfa) << endl;
							//for now the diffrenxe in speed is 15^2
							int a = 175;//(pow(bulletSpeed,2) - pow(EnemeySpeed,2));

							int b = 2*rangeToEnemy * pow(EnemeySpeed,2) * cos(alfa);
							int c = -(pow(EnemeySpeed, 2)* pow(rangeToEnemy, 2));
							cout <<"a:" << a << "  b:" << b << "  c: " << c << endl;
							int x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
							int x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
							cout << "Value of the s'es are :" << endl;
							cout <<"x1:" << x1 << " x2:" << x2 << endl;
							//cout << "jow ik draw the bullet line" << endl;
							float posx;
							//if (x1 > 0) {
							//	float posx = x1;
							//}
							//if (x1 < 0 && x2 > 0) {
							//	float posx = x2;
							//}
							posx = x1;
							
							//calculate the point where the bullet would intercept the enemy
							cout << "Calulting intercet point" << endl;
							PointF  BulletIntercept = {	(posEnemy[0] + posx) ,  (posEnemy[1] )};
							cout << "Poition Enemy :" << endl;
							cout << "x : " << posEnemy[0] << "  y:" << posEnemy[1] << endl;
							cout << "x:" << BulletIntercept[0] << "   y: " << BulletIntercept[1] << endl;
							//make a new bullet with the corresponding data
							FiredBullet* bullet = new FiredBullet(BulletIntercept,posTurret,posTurret,bulletSpeed);
							bulletvector.push_back(bullet);

							//update track id of the turret
							turretvector.at(i)->Aim(enenemyvector.at(j)->_id);



						



				}

			}
			//destroy turret
			else {
				//destroy the turret
				delete turretvector.at(i);
				//destroy the turret from the turret vector
				turretvector.erase(turretvector.begin() + i);	//(enenemyvector.begin() + i)
			}

		}
}

//make turret at a poistion (if it is possible)
void makeTurret(float x,float y) {
	int posx = x/20;
	int posy = y/20;
	// do not place turrets at the edge of the path -> a miniumum of 1 tile should be between the turret and the path
	if(Map[(posx+1)][(posy+1)] != '/' && Map[(posx -1)][(posy -1)] != '/'&& Map[(posx -1)][(posy )] != '/' && Map[(posx)][(posy - 1)]) {
		Color color = { 0.2f, 1, 0.2f };
		PointF pos = { x,y };
		//give the turret health -> later use
		int health = 100;
		//give the turret 0 upgrade -> basic turret -> later use
		int upgrade = 0;
		//give the turret a type -> later use
		int type = 0;
		//set the range of the turret
		int range = 150;
		//make a new turret and put it on the turret vector
		Turret* tur = new Turret(pos, color, range, health, upgrade, type);
		turretvector.push_back(tur);
	}
	else {
		cout << "Cannot place turret there, move your cursor and try again" << endl;
		return;
	}
}

//draw all of the turrets
void drawTurret() {
	//for every turret construct the turret
	for (unsigned i = 0; i < turretvector.size(); i++) {
		Color color = { 0.2f, 0.2f, 0.2f };
		PointF pos = turretvector.at(i)->_position;
		PointF begin2 = { (pos[0] - 20) ,(pos[1]) };
		PointF begin3 = { (pos[0]) , (pos[1] + 40) };
		PointF begin4 = { (pos[0] + 20) , (pos[1]) };
		Sqaure* sq = new Sqaure(pos, begin2, begin3, begin4, color);
		//put turret on the drawlist
		drawList.push_back(sq);
	}
}



//draw bullet's function
void drawBullet() {
	//define colors and width of the bullet
	Color color = { 0.9f, 0.9f, 0.9f };
	float lind = 2.0;
	//itterate over the bullet vector
	for (unsigned i = 0; i < bulletvector.size(); i++) {
		PointF BulletPos = bulletvector.at(i)->Move();

		// if bullet is out of screen 
		if (BulletPos[0] > windowWidth || BulletPos[1] > windowHeight || BulletPos[0] < 0 || BulletPos[1] < 0) {
			//delete the bullet 
			delete bulletvector.at(i);
			//delete the bulelt from the vector
			bulletvector.erase(bulletvector.begin() + i);	
			PlayerScore = PlayerScore + 100;
			cout << "Deleted an bullet" << endl;
		}
		else {
			
			bulletvector.at(i)->Update(BulletPos);
			cout << "Bullet position : " << endl;
			cout << BulletPos[0] << "  " << BulletPos[1] << endl;
			//PointF Bulletpos2 = bulletvector.at(i)->Move2();
			//bulletvector.at(i)->Update2(Bulletpos2);
			PointF BulletPos2 = { BulletPos[0], (BulletPos[1] + 10) };
			Line* bulletline = new Line{ BulletPos , BulletPos2 , color, lind };
			drawList.push_back(bulletline);


			//PointF end = bulletvector.at(i)
			////if the bullet end position is the same as the current enemy position eg a hit of the bullet
			//if (end[0] == posEnemy[0] && end[1] == posEnemy[1]) {
			//	
			//	enenemyvector.at(j)->Health(-10);
			//}
		}
	}
}

//if idle do all the calculations
void idle(int value) {

	//make the grid
	raster();
	//always make a turrent before the enemy

	//draw the turret's
	drawTurret();

	//draw the enemy's
	drawEnemy();
	//make a new turret
	drawBullet();

	//cal the display function -> draw everything 
	glutPostRedisplay();
	//cal this function agains
	glutTimerFunc(100, idle, 100);
}



//
//void alarm(int alarmNumber)
//{
//    if(alarmNumber == 112) {
//        cout << "Ring Ring!!! This was alarm 112!" << endl;
//        cout << "Next alarm will ring in 100 ms." << endl;
//
//        // Register another timer with a different number that triggers after 100 ms
//        glutTimerFunc(100, alarm, 1337);
//    } else {
//        cout << "Ring Ring!!! Alarm with alarmnumber " << alarmNumber << " called!" << endl;
//    }
//}

//---------------------------------------------------------------------------
// void reshape(int w, int h)
void reshape(int w, int h) 
{    
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
	//call the raster function again
	raster();
}

//---------------------------------------------------------------------------
// void display(void)
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);   // clear the backbuffer
	//drawtext(keytext, 100, 100);

	//draw everything on the drawlist
	for (Drawable* drawable : drawList){ 
		drawable->draw(); 
		
	}
	
    // Visualize the drawing commands
    glFlush();            // Execute all commands waiting to be executed
    glutSwapBuffers();    // Swap the backbuffer and frontbuffer
	//clear the drawing list
	drawList.clear();
}

//read teh inut from the main game and do corresponding stuff with it
void keyfunc(unsigned char key, int x, int y) {
	int seneY;
	seneY = windowHeight - y;
	if (key == 't') {
		cout << "Making a turret at cursor poistion" << endl;
		makeTurret(x,seneY);
	}
	if (key == 'e') {
		cout << "Spawning an enenemy" << endl;
		makeEnemy();
	}
	//starting game
	if (key == 's') {
		cout << "Wich map do you want to load ?\nType the map name :" << endl;
		cin >> filename;
		readFile(filename);
		cout << "Starting the game......." << endl;
		glutTimerFunc(10, idle, 10);
	}
	//quitting the game
	if (key == 'q') {
		cout << "Quitting the game" << endl;
		//_CrtDumpMemoryLeaks();
		exit(0);
	}

	//char c = key;
	//keytext = string{ c } +", " + to_string(x) + ", " + to_string(y);
}

//old debug fucntion
//void drawtext(std::string keytext, int x, int y) {
//
//	//cout << "jow ik ga ze uitrpinten" << endl;
//	glRasterPos2f(100, 100);
//	glColor3f(0, 0, 0);
//
//	for (char& c : keytext)
//	{
//		//cout << c << endl;
//		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
//	}
//
//}


//main function
int main(int argc, char* argv[])
{
    // Inialize GLUT
    glutInit(&argc, argv);
    // Initialize your program
    init();
    // Enter the main application loop
    // While in the main loop, your registered callbacks will be called
    cout << "Starting GLUT main loop..." << endl;
    glutMainLoop();
    return EXIT_SUCCESS;
}