#ifndef MAIN_H
#define MAIN_H

// Global constants (ONLY const)
const int windowWidth = 1024;
const int windowHeight = 768;
const char* windowTitle = "Final Task: Skeleton";

// Function declarations
int main(int argc, char* argv[]);
void init();

// Place your glut callback declarations here:
void reshape(int w, int h);
void display();
void alarm(int alarmnumber);
void keyfunc(unsigned char key, int x, int y);
void drawtext(std::string keytext, int x, int y);
void makeEnemy();
void makeTurret(float x,float y);
void drawEnemy();
void drawTurret();

#endif