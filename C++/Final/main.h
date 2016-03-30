#ifndef MAIN_H
#define MAIN_H
#include "glut.h"
#include "drawtools.h" 
// Global constants (ONLY const)
// main header file
const int windowWidth = 1024;
const int windowHeight = 768;
const char* windowTitle = "Final C Task: Tower Defense by: Martyn van Dijke";


// Function declarations
int main(int argc, char* argv[]);
void init();
// Place your glut callback declarations here:
void reshape(int w, int h);
void display();
//void alarm(int alarmnumber);
void keyfunc(unsigned char key, int x, int y);
//void drawtext(std::string keytext, int x, int y);
void makeEnemy();
void makeTurret(float x,float y);
void drawEnemy();
void drawTurret();
void raster();
void readFile(string filename);
void drawBullets(PointF posEnemy, int i);
void path();
void Start();
void text();
void DrawButton();
void CalcFPS();

#endif