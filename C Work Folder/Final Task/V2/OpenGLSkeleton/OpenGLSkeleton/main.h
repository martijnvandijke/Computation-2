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
void Lines(float begin_line[2], float end_line[2], float color[3], float line_width);
void Circles();
void DrawCircle(float cx, float cy, float r, int num_segments);
void circle(float x, float y, float r, int segments);
//void drawLine(const PointF& begin, const PointF& end, const Color& color, float lineWidth);

#endif