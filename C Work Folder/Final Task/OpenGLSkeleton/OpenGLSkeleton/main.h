#ifndef MAIN_H
#define MAIN_H
#include <string>


//extern std::string keytext;
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
void gettext(std::string keytext, int x, int y);
void keyfunc(unsigned char key, int x, int y);
void alarm(int alarmnumber);

#endif