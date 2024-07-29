#include <GL/glut.h>
void init(){
	glEnable(GL_DEPTH_TEST);
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1, 1, 100);
	glMatrixMode(GL_MODELVIEW);
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, -5);
	glRotatef(45, 1, 1, 1);
	glBegin(GL_QUADS);
//front
	glColor3f(1, 0, 0);
 glVertex3f(-1, -1, 1);
 glVertex3f(1, -1, 1);
 glVertex3f(1, 1, 1);
 glVertex3f(-1, 1, 1);
 // Back face
 glColor3f(0, 1, 0);
 glVertex3f(-1, -1, -1);
 glVertex3f(-1, 1, -1);
 glVertex3f(1, 1, -1);
 glVertex3f(1, -1, -1);
 // Top face
 glColor3f(0, 0, 1);
 glVertex3f(-1, 1, -1);
 glVertex3f(-1, 1, 1);
 glVertex3f(1, 1, 1);
 glVertex3f(1, 1, -1);
 // Bottom face
 glColor3f(1, 1, 0);
 glVertex3f(-1, -1, -1);
 glVertex3f(1, -1, -1);
 glVertex3f(1, -1, 1);
 glVertex3f(-1, -1, 1);
 // Right face
 glColor3f(1, 0, 1);
 glVertex3f(1, -1, -1);
 glVertex3f(1, 1, -1);
 glVertex3f(1, 1, 1);
 glVertex3f(1, -1, 1);
 // Left face
 glColor3f(0, 1, 1);
 glVertex3f(-1, -1, -1);
 glVertex3f(-1, -1, 1);
 glVertex3f(-1, 1, 1);
 glVertex3f(-1, 1, -1);
 glEnd();
	glutSwapBuffers();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3d");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}