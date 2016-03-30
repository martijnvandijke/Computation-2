// Made by Martyn van Dijke
// Student number : 087668
// Build date :
// Version : 
// Main file
///////////////////////////////

#include <iostream>
#include <string>
#include "glut.h"           // glut header file. Never include glut before stdlib.h!
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
#include <windows.h>
#pragma comment(lib, "Winmm.lib")

//global variables and defiinitions
using namespace std;
std::string keytext;
DrawList drawList;	//stuf that needs to be updated
DrawList Static;	//stuff that is static and does not need to be cleared from the list
DrawList DrawTextList;

string filename;
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
vector<Button*> ButtonVector;

//other global variables
int NumberFrames = 0;
int currentTime = 0;
int fps;
int PrevTime = 0;
int WaitTme = 250;
int lose = 0;
//only to be excuted once
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
    glClearColor(0.91015625, 0.88671875, 0.65234375, 0.2);               // Set background color to white 
    // Keep them like this if you don't need fancy options
    glMatrixMode(GL_PROJECTION);    // Next lines will adjust the projection matrix
    glLoadIdentity();               // Reset projection matrix to the identity matrix
    // Set the size of the viewport (drawing grid) in pixels
    // We are looking at the rectangle from (0,0) to (windowWidth,windowHeight)
    gluOrtho2D(0, windowWidth, 0, windowHeight);
    glMatrixMode(GL_MODELVIEW);
	Start();
}

//draw the start screen -> fancy opening of the game under devlopement
void Start() {

}

//read the map file from a .txt file
void readFile(string filename) {
	string word;
	ifstream fp;
	MapName = filename;
	int CountLines = 0;
	filename = filename + ".txt";
	fp.open(filename);
	if (fp.fail()) {
		cout << "Error parsing with the file \nPlease try again" << endl;
		return;
	}

	while (	getline(fp, word)){
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
	Color color = { 0.40625,0.76171875,0.63671875 };
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
			if ((windowWidth - 200) > varx) {
				PointF posPixel = { varx , vary };
				Circle* dots = new Circle(posPixel, color, radius, seg);
				Static.push_back(dots);
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

			if (Map[i][j] == '/' ) { 
				//draw the path where enemy's walk
				Color color = { 0.47265625, 0.33203125, 0.28125 };
				PointF begin1 = { x,y };
				PointF begin2 = { (x),(y+20) };
				PointF begin3 = { (x-20),(y+20) };
				PointF begin4 = { (x - 20), (y) };
				Sqaure* sq = new Sqaure(begin1, begin2, begin3, begin4, color);
				Static.push_back(sq);
				//drawList.push_back(sq);
			}
			//path where building is allowed
			if (Map[i][j] == '*' || Map[i][j] == 'T') {
				//draw the building site
				Color color = { 0 , 0.47265625, 0.41796875 };
				PointF begin1 = { x,y };
				PointF begin2 = { (x),(y + 20) };
				PointF begin3 = { (x - 20),(y + 20) };
				PointF begin4 = { (x - 20), (y) };
				Sqaure* sq = new Sqaure(begin1, begin2, begin3, begin4, color);
				Static.push_back(sq);
				//drawList.push_back(sq);
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
				Static.push_back(sq);
				//drawList.push_back(sq);
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
	float speed = 1;
	int health = 100;
	Enemy* en = new Enemy(begin1, begin1, speed, health);
	enenemyvector.push_back(en);
}

//draw the enemy's + walk alogirthm
void drawEnemy() {
	Color color = { 0.12890625, 0.5859375, 0.94921875 };
	float r = 22;
	//number of triganles that need to be drawn
	int seg = 20;
	for (unsigned i = 0; i<enenemyvector.size(); i++) {
		PointF curpos = enenemyvector.at(i)->_current;
		//if the enemy is out of the screen
		if (curpos[0] > windowWidth || curpos[1] > windowHeight) {
			//delete the enemy
			delete enenemyvector.at(i);
			//cout << "Deleted an enemy" << endl;
			//delete the enemy from the enemy vector
			enenemyvector.erase((enenemyvector.begin() + i));
		}

		//enemy is still in the screen
		else {
			PointF curpos = enenemyvector.at(i)->_current;

			//decrease the enemy health if a bullet hits the enemy
			for (unsigned j = 0; j < bulletvector.size(); j++) {
				PointF Bullet = bulletvector.at(j)->_begin;
				//calulate the diffrence in position
				float dx = abs(  Bullet[0]	 - curpos[0]);
				float dy = abs(  Bullet[1]	- curpos[1]);
				//cout << "dx :" << dx << "dy:" << dy << endl;
				//bullet and enemy are at the same poition

				//if the distnace is smaller tne the radius of the object
				if ( dx < 20 &&	dy < 20	) {
					enenemyvector.at(i)->Health(10);;
					//cout << "Damaged an enemy" << endl;
					PlayerScore = PlayerScore + 10;
					PlaySoundW(L"point.wav", NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
					//delete teh bullet 
					delete bulletvector.at(j);
					bulletvector.erase((bulletvector.begin() + j));
				}

			}


			//walk algorithm is good but could do better
			if (enenemyvector.at(i)->_health > 0) {
				int curx = curpos[0] /20;
				int cury = curpos[1] / 20;
				// get the map character that is 20 pixels further
				char nextCharXplus = Map[(curx+1)][cury];
				char nextCharYplus = Map[curx][(cury + 1)];
				char nextCharXmin =	Map[(curx - 1)][cury];
				char nextCharYmin = Map[curx][(cury - 1)];

				//if the enemy is at the end of the defense
				if (Map[(curx)][cury] == 'E') {
					//delete the enemy
					delete enenemyvector.at(i);
					//delete the enemy from the enemy vector
					enenemyvector.erase((enenemyvector.begin() + i));
					PlayerHealth = PlayerHealth - 30;
					PlaySoundW(L"loss.wav", NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
					continue;
				}
				//once the end line is insight
				if (Map[(curx + 2)][cury] == 'E') {
					PointF posEnemy = enenemyvector.at(i)->Move(1, 0);
					enenemyvector.at(i)->Update(posEnemy);
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
					Circle* cirle = new Circle(posEnemy, color, r, seg);
					drawList.push_back(cirle);
					drawBullets(posEnemy, i);
					continue;
				}
				// move 20 y pixels right
				if (nextCharYplus == '/' && Map[(curx)][(cury +2)] ) {
					PointF posEnemy = enenemyvector.at(i)->Move(0,1);
					enenemyvector.at(i)->Update(posEnemy);
					Circle* cirle = new Circle(posEnemy, color, r, seg);
					drawList.push_back(cirle);
					drawBullets(posEnemy, i);
					continue;
				}
				// move 20 x pixels rght
				if (nextCharXplus == '/' && Map[(curx + 2)][cury]== '/'	) {				
					PointF posEnemy = enenemyvector.at(i)->Move(1, 0);
					enenemyvector.at(i)->Update(posEnemy);
					Circle* cirle = new Circle(posEnemy, color, r, seg);
					drawList.push_back(cirle);
					drawBullets(posEnemy, i);
					continue;
				}
				//move 20 pixels down
				if (nextCharYmin == '/' && Map[curx][(cury - 2)] == '/'  ) {
					PointF posEnemy = enenemyvector.at(i)->Move(0, -1);
					enenemyvector.at(i)->Update(posEnemy);
					Circle* cirle = new Circle(posEnemy, color, r, seg);
					drawList.push_back(cirle);
					drawBullets(posEnemy, i);
					continue;
				}
				//move 20 pixels left
				if (nextCharXmin == '/') {
					PointF posEnemy = enenemyvector.at(i)->Move(-1, 0);
					enenemyvector.at(i)->Update(posEnemy);
					Circle* cirle = new Circle(posEnemy, color, r, seg);
					drawList.push_back(cirle);
					drawBullets(posEnemy, i);				
					continue;
				}
				else {
					cout << "Error unable to move the enemy" << endl;
					continue;
 				}


			}
			else	//the enemy has zero health
			{
					cout << "Deleted an enenemy" << endl;
					//delete the enemy
					delete enenemyvector[i];
					//delete the enemy from the enemy vector
					enenemyvector.erase((enenemyvector.begin() + i));
			}
		}
	}
}



//caclulate the interscet point of the bullet to be fired and the enenemy ->need some not x direction debuggin
void drawBullets(PointF posEnemy, int j){
		//initilize functions
		Color color = { 0.9f, 0.9f, 0.9f };
		float lind = 2.0;
		int bulletlenght = 4;

		//loop trough all the turrets
		for (unsigned i = 0; i < turretvector.size(); i++) {
			//get current time and the time the turret has last fired
			int currentTime = glutGet(GLUT_ELAPSED_TIME);
			int TimeTurret = turretvector.at(i)->_lastTime;

			//if the turret is allowed to fire
			if ((currentTime - TimeTurret) > WaitTme) {

				//if turret health is positive ->later function
				if (turretvector.at(i)->_health > 0) {
					//get the distance between the turret and enemy

					PointF posTurret = turretvector.at(i)->_position;
					float dy = abs(posEnemy[1] - posTurret[1]);
					float dx = abs(posEnemy[0] - posTurret[0]);

					//caclulate range to enemy
					float rangeToEnemy = sqrt((pow(dx, 2) + pow(dy, 2)));
					
					//if enemy is in the range
					if (rangeToEnemy < turretvector.at(i)->_range) {
						// As from the Part 2A. PDF
						int a = (pow(turretvector.at(i)->_bulletSpeed, 2) - pow(enenemyvector.at(j)->_speed, 2));	//static for the same bullet & enemey
						float alfa = atan((dy / dx));
						int b = 2 * rangeToEnemy* pow(enenemyvector.at(j)->_speed, 2)*cos(alfa);	//variable depending on the distance from turret to object
						int c = -pow(enenemyvector.at(j)->_speed, 2)* pow(rangeToEnemy, 2);
						//cout << a << " b: " << b << " c: " << c << endl;
						//calulating the outcomes for s
						int x_1 = (-b + sqrt((pow(b, 2) - 4 * a*c))) / (2 * a);
						int x_2 = (-b - sqrt((pow(b, 2) - 4 * a*c))) / (2 * a);
						int posx = x_1;
						int posy = 0;
						PointF BulletIntercept = { (posEnemy[0] + x_1)	, (posEnemy[1] + posy) };
						//cout << BulletIntercept[0] << endl;
						FiredBullet* bullet = new FiredBullet(BulletIntercept, posTurret, posTurret, turretvector.at(i)->_bulletSpeed);
						bulletvector.push_back(bullet);
						turretvector.at(i)->TimeUpdate(currentTime);
					}

				}
			}


		}

}

//make turret at a poistion and check if this is possible
void makeTurret(float x,float y) {
	int posx = x/20;
	int posy = y/20;
	// do not place turrets at the edge of the path -> a miniumum of 1 tile should be between the turret and the path and do not place the turret at a place where there is already a turret
	if(Map[(posx+1)][(posy+1)] != '/' && Map[(posx -1)][(posy -1)] != '/'&& Map[(posx -1)][(posy )] != '/' && Map[(posx)][(posy - 1)]  != '/' && Map[(posx)][(posy)] != '/' && Map[(posx)][(posy+1)] != '/' && (Map[posx][posy] != 'T' && Map[(posx+1)][posy] !='T' && Map[(posx)][(posy+1)]  != 'T' && Map[(posx+1)][(posy+1)] != 'T' )	){
		//store the turret poisition of the map, prevent the paler from placing two turrets on eachother
		Map[posx][posy] = 'T';
		Map[(posx + 1)][(posy + 1)] = 'T';
		Map[(posx)][(posy + 1)] = 'T';
		Map[(posx + 1)][posy] = 'T';

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
		Turret* tur = new Turret(pos, color, range, health, upgrade, type, glutGet(GLUT_ELAPSED_TIME) );
		turretvector.push_back(tur);

		//draw the turret's
		drawTurret();
	}
	else {
		cout << "Cannot place turret there, move your cursor and try again" << endl;
		return;
	}

}

//draw all of the turrets
void drawTurret() {
	//for every turret construct the corresonding turret
	for (unsigned i = 0; i < turretvector.size(); i++) {
		Color color = { 0.2f, 0.2f, 0.2f };
		PointF pos = turretvector.at(i)->_position;
		PointF begin2 = { (pos[0] - 20) ,(pos[1]) };
		PointF begin3 = { (pos[0]) , (pos[1] + 40) };
		PointF begin4 = { (pos[0] + 20) , (pos[1]) };
		Sqaure* sq = new Sqaure(pos, begin2, begin3, begin4, color);
		//put turret on the Static drawlist
		Static.push_back(sq);
	}
}

//draw the actual bullet's as is seen on screen
void drawBullet() {
	//define colors and width of the bullet
	Color color = { 0.9f, 0.9f, 0.9f }; //white bullets
	float lind = 2.0;
	//itterate over the bullet vector
	for (unsigned i = 0; i < bulletvector.size(); i++) {
		PointF BulletPos = bulletvector.at(i)->Move();

		// if bullet is out of screen 
		if (BulletPos[0] > windowWidth || BulletPos[1] > windowHeight || BulletPos[0] < 0 || BulletPos[1] < 0) {
			//delete the bulelt from the vector and the pointer to the bullet
			delete bulletvector.at(i);
			bulletvector.erase(bulletvector.begin() + i);	
			
		}
		else {
			//update the movement of the bullet
			bulletvector.at(i)->Update(BulletPos);
			//draw the bullet		+5 becuase of the width of the bullet
			PointF BulletPos2 = { BulletPos[0], (BulletPos[1] + 5) };
			Line* bulletline = new Line{ BulletPos , BulletPos2 , color, lind };
			//push to the draw list
			drawList.push_back(bulletline);
		}
	}
}



//if idle do all the calculations
void idle(int value) {
	//calulate the number of Frames
	CalcFPS();
	
	//draw the enemy's
	drawEnemy();
	//make a new turret
	drawBullet();
	
	
	text();
	
	//display function -> draw everything 
	glutPostRedisplay();

	//update of the global variables
	if (PlayerHealth > 0 ){
		glutTimerFunc(20, idle, 20);
	}
	else {
		cout << "You have lot the game with a score of :" << PlayerScore << endl;
		PlaySoundW(L"loss.wav", NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
		lose = 1;
		text();
		display();

		Sleep(8000);
		exit(0);
	}

}

//draw all the text that needs to be displayed
void text() {
	//definition stuff
	float x = (windowWidth - 180);
	float y = windowHeight - 100;
	Color color = { 0.375, 0.48828125, 0.54296875 };
	Color loseColor = { 1,1,1};
	PointF posF = { x, (y+50) };
	Text* texttodispF = new Text("FPS :", color, posF);
	DrawTextList.push_back(texttodispF);
	PointF pos2F = { (x + 125), (y+50) };
	Text* texttodisp2F = new Text(to_string(fps), color, pos2F);
	DrawTextList.push_back(texttodisp2F);

	//print the plaer health -> fancy icon ?
	PointF pos = { x, y };
	Text* texttodisp = new Text("Player Health : ", color, pos);
	DrawTextList.push_back(texttodisp);
	PointF pos2 = { (x +125), y };
	Text* texttodisp2 = new Text(to_string(	PlayerHealth)	, color, pos2);
	DrawTextList.push_back(texttodisp2);

	//print the player Score
	PointF pos3 = { x, (y -50) };
	Text* texttodisp3 = new Text("Player Score : ", color, pos3);
	DrawTextList.push_back(texttodisp3);
	PointF pos4 = { (x+125), (y - 50) };
	Text* texttodisp4 = new Text(to_string(PlayerScore), color, pos4);
	DrawTextList.push_back(texttodisp4);

	//print current player map 
	PointF pos5 = { x, (y - 100) };
	Text* texttodisp5 = new Text("Curret map : ", color, pos5);
	DrawTextList.push_back(texttodisp5);
	PointF pos6 = { (x + 125), (y - 100) };
	Text* texttodisp6 = new Text(MapName, color, pos6);
	DrawTextList.push_back(texttodisp6);

	if (lose == 1) {
		PointF pos6 = { (windowWidth/2 -100),(windowHeight/2)  };
		Text* texttodisp6 = new Text("You have lost this game ", loseColor, pos6);
		DrawTextList.push_back(texttodisp6);
		
	}

}

void CalcFPS() {
	NumberFrames++;
	currentTime = glutGet(GLUT_ELAPSED_TIME);
	int DeltaTime = currentTime - PrevTime;
	if (DeltaTime > 1000) {
		fps = NumberFrames / (DeltaTime / 1000.0f);
		PrevTime = currentTime;
		NumberFrames = 0;
	}

}

//draw the game Gui buttons -> static draw so only has to be draw once
void DrawButton() {
	float x = (windowWidth - 180);
	float padding = 5;
	Color Textcolor = { 0.375, 0.48828125, 0.54296875 };
	Color ButtonColor = { 0.99609375, 0.33984375, 0.1328125 };
	//start button
	PointF begin = { (x+150),375 };
	PointF begin2 = { (x+150),  400};
	PointF end = { x,400 };
	PointF end2 = { x , 375 };
	int mode = 1;
	Sqaure* sq = new Sqaure(begin, begin2, end, end2, ButtonColor);
	Static.push_back(sq);
	PointF PosText = { (x+padding) , (end2[1] + padding) };
	string text_to = "Start Game";
	Text* button_text = new Text(text_to, Textcolor, PosText);
	Static.push_back(button_text);
	//make Button class
	Button* start = new Button(text_to, mode, ButtonColor, begin, end, begin2, end2);
	//add to Button vector
	ButtonVector.push_back(start);

	//Spawn Enemy button
	PointF begin3 = { (x + 150),300 };
	PointF begin4 = { (x + 150),  325 };
	PointF end3 = { x,325 };
	PointF end4 = { x , 300 };
	int mode2 = 1;
	Sqaure* sq2 = new Sqaure(begin3, begin4, end3, end4, ButtonColor);
	Static.push_back(sq2);
	PointF PosText2 = { (x + padding) , (end4[1] + padding) };
	string text_to2 = "Spawn Enemy";
	Text* button_text2 = new Text(text_to2, Textcolor, PosText2);
	Static.push_back(button_text2);
	//make button class
	Button* spawn = new Button(text_to2,mode2,ButtonColor,begin3,end3,begin4,end4);
	//add to Button vector
	ButtonVector.push_back(spawn);
	
}

//menu types declaration
enum MENU_TYPE
{
	MENU_FRONT,
	MENU_SPOT,
	MENU_BACK,
	MENU_BACK_FRONT,
};

//function for the submenu of the Load Map data
void SubMenu2(int item) {
	switch (item)
	{
	case 1: {
		filename = "map1";
		readFile(filename);
		cout << "Starting map 1......." << endl;
		glutTimerFunc(10, idle, 10);
		raster();
		return;
	}
	case 2: {
		filename = "map2";
		readFile(filename);
		cout << "Starting map 2......." << endl;
		glutTimerFunc(10, idle, 10);
		raster();
		return;
	}
	case 3: {
		filename = "map3";
		readFile(filename);
		cout << "Starting map 3......." << endl;
		glutTimerFunc(10, idle, 10);
		raster();
		return;
	}
	default:
		break;
	}

}

//function for the menu
void menu(int item)
{
	switch (item){
		case MENU_FRONT:
	
		//Generate enenmy
		case MENU_SPOT:{
			makeEnemy();
			return;
		}
		case MENU_BACK: {

		}
		//Quit the Game
		case MENU_BACK_FRONT:{
			exit(0);
			return;
		}
		break;
		default:
		{
			
		}
		break;
	}
	glutPostRedisplay();
	return;
}

//function that handles mouse clicks 
void MouseClick(int button, int state, int x, int y){
	int SenseY = windowHeight - y;
	int x_map = x / 20;
	int y_map = SenseY / 20;



	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		
		//if a mouse click on the map eg placing a turret
		if (Map[x_map][y_map] == '*') {
			makeTurret(x,SenseY);
			return;
		}
		else {
			for (unsigned i = 0; i < ButtonVector.size(); i++) {
				
				PointF begin = ButtonVector.at(i)->_begin;
				//PointF begin2 = ButtonVector.at(i)->_begin2;
				PointF end = ButtonVector.at(i)->_end;
				//PointF end2 = ButtonVector.at(i)->_end2;

				//if mouse click was on button
				if(	x > end[0] && x < begin[0] && SenseY > begin[1] && SenseY < end[1] )
				{
					string text = ButtonVector.at(i)->_text;
					if (text == "Start Game") {
						readFile("map1");
						cout << "Starting the game......." << endl;
						glutTimerFunc(10, idle, 10);
						raster();
					}
					if (text == "Spawn Enemy") {
						makeEnemy();
					}
				}
			}
		}
		
	}
}

//handle reshapes of the screen
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

	//draw all the Static Stuff -> map data
	for (Drawable* drawable : Static) {
		drawable->draw();
	}
	//draw everything on the drawlist
	for (Drawable* drawable : drawList){ 
		drawable->draw(); 
		//delete the pointers to the drawable on the drawlist
		delete drawable;
	}

	//lastly draw the text -> ensures the text is always draw on top
	for (Drawable* drawable : DrawTextList) {
		drawable->draw();
		//delete the ponter to the drawable
		delete drawable;
	}
    // Visualize the drawing commands
    glFlush();            // Execute all commands waiting to be executed
    glutSwapBuffers();    // Swap the backbuffer and frontbuffer
	//clear the drawing & text list
	drawList.clear();
	DrawTextList.clear();
}

//read the inut from the main game and do corresponding stuff with it
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
		raster();
	}
	//quitting the game
	if (key == 'q') {
		cout << "Quitting the game" << endl;
		exit(0);
	}
}

//main function
int main(int argc, char* argv[])
{
    // Inialize GLUT
    glutInit(&argc, argv);
    // Initialize your program
    init();
    // Enter the main application loop

	//fancy asci art :)
	printf(R"EOF(
________                                ________     ________                        
___  __/________      ______________    ___  __ \_______  __/_______________________ 
__  /  _  __ \_ | /| / /  _ \_  ___/    __  / / /  _ \_  /_ _  _ \_  __ \_  ___/  _ \
_  /   / /_/ /_ |/ |/ //  __/  /        _  /_/ //  __/  __/ /  __/  / / /(__  )/  __/
/_/    \____/____/|__/ \___//_/         /_____/ \___//_/    \___//_/ /_//____/ \___/                                                                                                                                                                            

)EOF");
	
	printf(R"EOF(				                                                      
|\/| _. _| _  |_    |\/| _..__|_  ._     _.._  | \oo|  _ 
|  |(_|(_|(/_ |_)\/ |  |(_||  |_\/| | \/(_|| | |_/|||<(/_
	             /              /                 _|     
)EOF");
	cout << "Press start the game to begin...." << endl;
	DrawButton();
	glutMouseFunc(MouseClick);
	int SubMenu = glutCreateMenu(SubMenu2);
	glutAddMenuEntry("Map 1", 1);
	glutAddMenuEntry("Map 2", 2);
	glutAddMenuEntry("Map 3", 3);
	// Create a menu
	int GameMenu= glutCreateMenu(menu);
	// Add menu items
	//glutAddMenuEntry("Start the Game", MENU_FRONT);
	glutAddSubMenu("Start map :", SubMenu);
	glutAddMenuEntry("Spawn an Enemy", MENU_SPOT);
	glutAddMenuEntry("Quit the game", MENU_BACK_FRONT);
	// Associate the right mouse button with menu
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	glutMainLoop();
    return EXIT_SUCCESS;
}