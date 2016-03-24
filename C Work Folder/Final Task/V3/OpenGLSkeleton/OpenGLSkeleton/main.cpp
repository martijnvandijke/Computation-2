
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
#include "FiredBullet.h"
#include <fstream>
#include <map>


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
vector<Enemy*> enenemyvector;	//vector contains all the enemey
vector<Turret*> turretvector;	//vector contains all the turrets
vector<FiredBullet*> bulletvector;
//vector<Bullet*> bulletvector;	//bullet vector contains calulated intersection point + 
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
	makeTurret(100,300);
	makeEnemy();
	raster();
}

//read a the map file
void readFile(string filename) {
	string word;
	ifstream fp;
	//Map[100][100] = {};
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

		//count the "y" 
		CountLines++;
		//cout << word << endl;
		for (unsigned i = 0; i < word.size(); i++) {
			//get char at place in string
			char c = (word.at(i));
			//cout << c << endl;
			//store char in the map
			Map[i][(CountLines - 1)] = c;

		}
	}

	// Close the file
	fp.close();

}


//make a grid 
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
			//cout << "map contins:" << endl;
			//cout << Map[i][j] << endl;
			//path for the enemy
			if (Map[i][j] == '/') { 
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
				Color color = { 0.4f, 0.4f, 0.4f };
				PointF begin1 = { x,y };
				PointF begin2 = { (x),(y + 20) };
				PointF begin3 = { (x - 20),(y + 20) };
				PointF begin4 = { (x - 20), (y) };
				Sqaure* sq = new Sqaure(begin1, begin2, begin3, begin4, color);
				drawList.push_back(sq);
			}

			if (Map[i][j] == 'E') {
				Color color = { 1.0f, 0.4f, 0.4f };
				PointF begin1 = { x,y };
				PointF begin2 = { (x),(y + 20) };
				PointF begin3 = { (x - 20),(y + 20) };
				PointF begin4 = { (x - 20), (y) };
				Sqaure* sq = new Sqaure(begin1, begin2, begin3, begin4, color);
				drawList.push_back(sq);
			}

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
			enenemyvector.erase((enenemyvector.begin() + i));
		}

		else {
			if (enenemyvector.at(i)->_health > 0) {
				PointF curpos = enenemyvector.at(i)->_current;
				int curx = curpos[0] /20;
				int cury = curpos[1] / 20;
				cout << curx << cury << endl;
				//cout << "map contains :" << endl;
				//cout << Map[10][10] << endl;
				// get the map character that is 20 pixels further
				char nextCharXplus = Map[(curx+1)][cury];
				char nextCharYplus = Map[curx][(cury + 1)];
				char nextCharXmin =	Map[(curx - 1)][cury];
				char nextCharYmin = Map[curx][(cury - 1)];

				if (Map[(curx)][cury] == 'E') {
					PointF posEnemy = enenemyvector.at(i)->Move(1, 0);	
					cout << "Enemy has been let trough the defenses" << endl;
					enenemyvector.at(i)->Update(posEnemy);
					r = enenemyvector.at(i)->_health;
					Circle* cirle = new Circle(posEnemy, color, r, seg);
					drawList.push_back(cirle);
					drawBullets(posEnemy, i);
					//Bullet(posEnemy, i);
					continue;
				}

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


				//cout << "ik ben tot hiero gekomen" << endl;
				//cout << nextCharXplus << nextCharYplus << nextCharXmin << nextCharYmin << endl;
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
		//cout << "going to put bullets on the list" << endl;
		//initilize functions
		Color color = { 0.9f, 0.9f, 0.9f };
		float lind = 2.0;
		int bulletlenght = 4;

		//loop trough all the turrets
		for (unsigned i = 0; i < turretvector.size(); i++) {

			//if turret health is positive ->later function
			if (turretvector.at(i)->_health > 0) {
					//get the poistion of the turrets
					float dx =  turretvector.at(i)->_position[0] - posEnemy[0];
					float dy =  turretvector.at(i)->_position[1] - posEnemy[1];
					//caclulate range to enemy
					float rangeToEnemy = sqrt(	pow(dx,2)  + pow(dy,2)	);
					//cout << rangeToEnemy << endl;
					//if enemy is in the range
					if (rangeToEnemy < turretvector.at(i)->_range) {
						cout << "enemy in range" << endl;
						//get position of the turret
						PointF turPos = turretvector.at(i)->_position;
						//get the aiming id of the turret
						int aimingId = turretvector.at(i)->_aiming;
						//s^2 ( V_b^2 - V_e^2) + 1s*r*V_e^2*cos(a) - V_e^2*r^2
						//if the current turret is locked on to the current enemy
						//if (aimingId == enenemyvector.at(j)->_id) {
							//draw bullet to the enemy
							PointF posTurret = turretvector.at(i)->_position;
							int bulletSpeed = turretvector.at(i)->_bulletSpeed;
							int EnemeySpeed = enenemyvector.at(j)->_speed;
							float dy = abs(posEnemy[1] - posTurret[1]);
							float dx = abs(posEnemy[0] - posTurret[0]);
							cout << "abs dx ,dy" << endl;
							cout << dx << "   "<< dy << endl;
							float alfa = tan((dy/dx));
							cout << alfa << endl;
							cout << cos(alfa) << endl;
							int a = 175;//(pow(bulletSpeed,2) - pow(EnemeySpeed,2));
							int b = rangeToEnemy * pow(EnemeySpeed,2) * cos(alfa);
							int c = -(pow(EnemeySpeed, 2)* pow(rangeToEnemy, 2));
							cout << a << "  " << b << "   " << c << endl;
							int x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
							int x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
							cout << "Value of the s'es are :" << endl;
							cout << x1 << " " << x2 << endl;
							cout << "jow ik draw the bullet line" << endl;
							float posx;
							if (x1 > 0) {
								float posx = x1;
							}
							if (x1 < 0 && x2 > 0) {
								float posx = x2;
							}
							posx = x1;
							float posy = posEnemy[1] + 	(dy / 15);
							//calculate the point where the bullet would intercept the enemy
							cout << "calulting intercet point" << endl;
							PointF  BulletIntercept = {	(posEnemy[0] + posx) ,  (posy )};
							cout << BulletIntercept[0] << "    " << BulletIntercept[1] << endl;
							PointF BulletStart = { posTurret[0], (posTurret[1] +4) };
							FiredBullet* bullet = new FiredBullet(BulletIntercept,posTurret,posTurret,bulletSpeed);
							bulletvector.push_back(bullet);
							//PointF BulletPos = bulletvector.at(i)->Move();
							//Bullet* but = new Bullet(BulletIntercept, posTurret);
							//Bullet* bullet = new Bullet(BulletIntercept,BulletStart);

							//Line* bulletline = new Line{ BulletPos , turretvector.at(i)->_position , color, lind };
							//drawList.push_back(bulletline);
						
							//bulletvector.push_back(bulletline);
							//update track id of the turret
							turretvector.at(i)->Aim(enenemyvector.at(j)->_id);
						//}
						//no enemy in track
						//if(aimingId == 0) {
						//	cout << "jow ben heir" << endl;
						//	//get current pos of the first enemy
						//	PointF posEnemy = enenemyvector.front()->_current;


						//	Line* bulletline = new Line{ posEnemy, turretvector.at(i)->_position , color, lind };
						//	drawList.push_back(bulletline);
						//
						//	bulletvector.push_back(bulletline);
						//	//update track id of the turret
						//	turretvector.at(i)->Aim(enenemyvector.front()->_id);
						//}

						



				}

			}
			//destroy turret
			else {
				//destroy turret from the list
				delete turretvector.at(i);
				turretvector.erase(turretvector.begin() + i);	//(enenemyvector.begin() + i)
			}
		}
}

void makeTurret(float x,float y) {
	int posx = x/20;
	int posy = y/20;
	if(Map[posx][posy] != '/') {
		Color color = { 0.2f, 1, 0.2f };
		PointF pos = { x,y };
		int health = 100;
		int upgrade = 0;
		int type = 0;
		int range = 150;
		Turret* tur = new Turret(pos, color, range, health, upgrade, type);
		turretvector.push_back(tur);
	}
	else {
		cout << "connot place turret there" << endl;
		return;
	}
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

void drawBullet() {
	
	Color color = { 0.9f, 0.9f, 0.9f };
	float lind = 2.0;
	for (unsigned i = 0; i < bulletvector.size(); i++) {
		cout << "going to draw the bullets for real this time" << endl;

		PointF BulletPos = bulletvector.at(i)->Move();
		cout << "Bullet position : " << endl;
		cout << BulletPos[0] << "  "  << BulletPos[1] << endl;
		PointF Bulletpos2 =  bulletvector.at(i)->Move2();
		Line* bulletline = new Line{ BulletPos , Bulletpos2 , color, lind };
		drawList.push_back(bulletline);
		//PointF end = bulletvector.at(i)
		////if the bullet end position is the same as the current enemy position eg a hit of the bullet
		//if (end[0] == posEnemy[0] && end[1] == posEnemy[1]) {
		//	//
		//	enenemyvector.at(j)->Health(-10);
		//}
	}
}
//if idle do all the calculations
void idle(int value) {
	readFile("test");

	raster();
	//always make a turrent before the enemy

	//draw the turret's
	drawTurret();

	drawEnemy();
	//make a new turret
	drawBullet();

	//cal the display function -> draw everything 
	glutPostRedisplay();
	//cal this function agains
	glutTimerFunc(160, idle, 100);
}




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
	int seneY;
	seneY = windowHeight - y;
	if (key == 't') {
		//cout << "jow ik maak een turret aan" << endl;
		makeTurret(x,seneY);
	}
	if (key == 'e') {
		cout << "jow ik maak een enemy aan" << endl;
		makeEnemy();
	}

	char c = key;
	keytext = string{ c } +", " + to_string(x) + ", " + to_string(y);
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