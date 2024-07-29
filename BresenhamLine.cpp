#include <GL/glut.h>
#include <stdio.h>
int startx, starty, endx, endy;
void init(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}
void set_pixel(int x, int y){
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void bresenhamLine(int xi, int yi, int endx, int endy){
	int dx = abs(endx - xi);
	int dy = abs(endy - yi);
	int sx = (xi < endx) ? 1 : -1;
	int sy = (yi < endy) ? 1 : -1;
	int err = dx - dy;
	while (1){
		set_pixel(xi, yi);
		if (xi == endx && yi==endy)
			break;
		int en = 2 * err;
		if (en > -dy)
		{
			err -= dy;
			xi += sx;
		}
		if (en < dx){
			err += dy;
			yi += sy;
		}
	}
}
void display(){
	glColor3f(1, 1, 1);
	bresenhamLine(startx, starty, endx, endy);
	glFlush();
}
int main(int argc, char** argv){
	printf("start point: ");
	scanf("%d %d", &startx, &starty);
	printf("End point: ");
	scanf("%d %d", &endx, &endy);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Br Line");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}