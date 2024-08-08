#include <GL/glut.h>
#include <cmath>
#define PI 3.14

void init(){
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50, 50, -50, 50);
}

void drawCircle(float x, float y, float radius){
	glBegin(GL_LINE_LOOP);
	for (int i=0; i <= 300; i++)
	{
		float angle = 2.0f * PI * i / 300;
		float dx = radius * cosf(angle);
		float dy = radius * sinf(angle);
		glVertex2f(x + dx, y + dy);
	}
	glEnd();
}

void display(){
	glBegin(GL_LINES);
	glVertex2f(-40, 30);
	glVertex2f(40, 30);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(-40,20);
	glVertex2f(40,20);
	glVertex2f(40,-20);
	glVertex2f(-40,-20);
	glEnd();

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
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("2d shit");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

