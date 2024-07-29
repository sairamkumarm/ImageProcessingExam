#include <GL/glut.h>
#include <cmath>
#define PI 3.14

void init(){
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50, 50, -50, 50);
}
void drawCircle(float x, float y, float radius){
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= 300; i++){
		float angle = 2.0f * PI * i / 300;
		float dx = radius * cosf(angle);
		float dy = radius * sinf(angle);
		glVertex2f(x+ dx, y +dy);
	}
	glEnd();
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	//line
	glBegin(GL_LINES);
	glVertex2f(-40, 30);
	glVertex2f(40, 30);
	glEnd();
	// rectangle
	glBegin(GL_LINE_LOOP);
	glVertex2f(-20, -10);
	glVertex2f(-20, 10);
	glVertex2f(20, 10);
	glVertex2f(20, -10);
	glEnd();
	// ploygon
	glBegin(GL_POLYGON);
	glVertex2f(0, 10);
	glVertex2f(-10, -10);
	glVertex2f(10, -10);
	glEnd();
	drawCircle(0, 0, 15);
	glFlush();
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutCreateWindow("2d Operations");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
// #include <GL/glut.h>
// #include <cmath>
// #define PI 3.14
// // Initialize OpenGL Graphics
// void init()
// {
//  glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
//  glColor3f(0.0, 0.0, 0.0); // Set drawing color to black
//  glMatrixMode(GL_PROJECTION); // Set the projection matrix
//  glLoadIdentity(); // Reset the projection matrix
//  gluOrtho2D(-50.0, 50.0, -50.0, 50.0); // Define the 2D orthographic projection
// }
// // Function to draw a circle
// void drawCircle(float x, float y, float radius) {
//  glBegin(GL_LINE_LOOP);
//  for (int i = 0; i <= 300; i++) {
//  float angle = 2.0f * M_PI * i / 300;
//  float dx = radius * cosf(angle);
//  float dy = radius * sinf(angle);
//  glVertex2f(x + dx, y + dy);
//  }
//  glEnd();
// }
// void display() {
//  glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
//  // Draw a line
//  glBegin(GL_LINES);
//  glVertex2f(-40.0, 30.0);
//  glVertex2f(40.0, 30.0);
//  glEnd();
//  // Draw a rectangle
//  glBegin(GL_LINE_LOOP);
//  glVertex2f(-20.0, -10.0);
//  glVertex2f(20.0, -10.0);
//  glVertex2f(20.0, -30.0);
//  glVertex2f(-20.0, -30.0);
//  glEnd();
//  // Draw a filled polygon (triangle)
//  glBegin(GL_POLYGON);
//  glVertex2f(0.0, 10.0);
//  glVertex2f(10.0, -10.0); 
//   glVertex2f(-10.0, -10.0);
//  glEnd();
//  // Draw a circle
//  drawCircle(0, 0, 15.0);
//  glFlush(); // Render now
// }
// int main(int argc, char** argv)
// {
//  glutInit(&argc, argv);
//  glutCreateWindow("Basic Geometric Operations"); // Create window with title
//  glutDisplayFunc(display); // Register display callback
//  init(); // Initialize graphics
//  glutMainLoop(); // Enter the event-processing loop
//  return 0;
// }