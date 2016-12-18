#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <windows.h>
#endif

#include <cmath>
#include "Vector.h"
#include "simulation.h"
#include <time.h>
#include <stdio.h>

void setDrawingColor(Vector color)
{
	glColor3f(color[0], color[1], color[2]);
}

void drawCircle(Vector center, double radius, Vector color, int num_points)
{
	double angle_dt = 2*M_PI/(double)num_points;

	setDrawingColor(color);

	glBegin(GL_TRIANGLE_FAN);

	glVertex2d(center[0], center[1]);

	for(int i=0; i<num_points; i++)
	{
		glVertex2d(center[0] + radius*sin(i*angle_dt), center[1] + radius*cos(i*angle_dt));
	}

	glVertex2d(center[0] + radius*sin(0), center[1] + radius*cos(0));

	glEnd();
}

double last_time;


Vector acc(2);
Vector spd(2);
Vector center(2);
Vector one_pos(2);
Vector two_pos(2);
Vector color(3);
Vector color_fixed(3);
Vector center_rotation(2);

Vertex *nodes;
int num_vertex;

void display() 
{
	double current_time = (double)glutGet(GLUT_ELAPSED_TIME)/1000.0;
	double elapsed_time = current_time - last_time;
	last_time = current_time;

/*	printVertices(nodes, num_vertex);
	printf("\n");*/
	simulate(nodes, num_vertex, elapsed_time);

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 0.0); // JMU Purple

	for (int i = 0; i < num_vertex; i++)
	{
		center = getPosition(nodes, i);
		if(nodes[i].fixed)
		{
			drawCircle(center, 0.1, color_fixed, 100);
		}
		else
		{
			drawCircle(center, 0.1, color, 100);
		}
	}

	for (int i = 0; i < num_vertex; i++)
	{
		for (int j = 0; j < nodes[i].num_neighbours; j++)
		{
			one_pos = getPosition(nodes, i);
			two_pos = getPosition(nodes, nodes[i].neighbours[j]);

			glBegin(GL_LINES);
			glVertex2f(one_pos[0], one_pos[1]);
			glVertex2f(two_pos[0], two_pos[1]);
			glEnd();
		}
	}

	glFlush();

	glutSwapBuffers();
	glutPostRedisplay();
}

void init() 
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // JMU Gold

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5.0, 5.0, -5.0, 5.0);

	last_time = (double)glutGet(GLUT_ELAPSED_TIME)/1000.0;

	acc[0] = -1.0;
	acc[1] = 0.0;
	spd[0] = 0.0;
	spd[1] = 1.0;
	center[0] = 1.0;
	center[1] = 0.0;
	color[0] = 1.0;
	color[1] = 0.0;
	color[2] = 1.0;
	color_fixed[0] = 0.0;
	color_fixed[1] = 0.0;
	color_fixed[2] = 1.0;
	center_rotation[0] = 0.0;
	center_rotation[1] = 0.0;
}

int main(int argc, char** argv) 
{
	initVertices(&nodes, &num_vertex, "../in/test_01.sim");
	printVertices(nodes, num_vertex);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Simulation");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}