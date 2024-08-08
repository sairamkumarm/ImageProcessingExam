#include <GL/glut.h>

void init(){
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}

void display(){
	glColor3f(1, 0, 0);
	glRecti(250, 300, 400, 350);
	glPushMatrix();

	glTranslatef(-100,-100, 0);
	glRecti(250, 300, 400, 350);
	glPopMatrix();
	glPushMatrix();

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
	glutCreateWindow("2d transformations");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}