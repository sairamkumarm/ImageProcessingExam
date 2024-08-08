#include <GL/glut.h>
#include <stdio.h>

int startx, starty, endx, endy;

void init(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}
void setpoint(int x, int y){
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void bresenhamLine(int xi, int yi, int xend, int yend){
	int dx = abs(xi - yend);
	int dy = abs(yi - yend);
	int err = dx - dy;
	int sx = (xi < xend) ? 1 : -1;
	int sy = (yi < yend) ? 1 : -1;
	while(1){
		setpoint(xi, yi);
		if (xi==xend && yi==yend){
			break;	
		}
		int en = 2 * err;
		if (en > -dy){
			err -= dy;
			xi += sx;
		}
		if (en < dx ){
			err += dx;
			yi += sy;
		}
	}
}

void display(){
	glColor3f(1, 1, 1);
	bresenhamLine(startx, starty, endx, endy);
	glFlush();
}

int main(int argc, char**argv){
	printf("enter coordinates startx starty endx endy: ");
	scanf("%d %d %d %d", &startx, &starty, &endx, &endy);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Bresenham Line");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}