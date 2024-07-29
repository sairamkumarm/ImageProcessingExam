#include <GL/glut.h>
#include <stdio.h>

void init(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0, 0, 1);
	glRecti(250, 300, 400, 350);
	glPushMatrix();

	glTranslatef(-100, -50, 0);
	glRecti(250, 300, 400, 350);
	glPopMatrix();
	glPushMatrix();

	glColor3f(1, 0, 0);
	glRotatef(20, 0, 0, 1);
	glRecti(250, 300, 400, 350);
	glPopMatrix();
	glPushMatrix();

	glScalef(0.5, 0.5, 1);
	glRecti(250, 300, 400, 350);
	glPopMatrix();
	glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("asdf");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}