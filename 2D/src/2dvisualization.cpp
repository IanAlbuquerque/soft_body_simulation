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
#include <string.h>

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

double g;
double h;
int rigid_bars_count;

void display() 
{
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

			if(nodes[i].rigid[j] == true)
			{
				glColor3f(0.0, 0.5, 0.0); // JMU Purple
			}
			else
			{
				glColor3f(1.0, 0.0, 1.0); // JMU Purple
			}
			glBegin(GL_LINES);
			glVertex2f(one_pos[0], one_pos[1]);
			glVertex2f(two_pos[0], two_pos[1]);
			glEnd();
		}
	}

	glFlush();

	glutPostRedisplay();
	glutSwapBuffers();
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

void update(void)
{
	double current_time = (double)glutGet(GLUT_ELAPSED_TIME)/1000.0;
	double elapsed_time = current_time - last_time;
	last_time = (double)glutGet(GLUT_ELAPSED_TIME)/1000.0;

	simulate(nodes, num_vertex, elapsed_time, g, h, rigid_bars_count);
}

bool can_move = false;
void mouse(int button, int state, int x, int y)
{
	Vector mouse(2);
	mouse[0] = x * 10.0 / 640.0 - 5.0;
	mouse[1] = -(y * 10.0 / 640.0 - 5.0);
	if(button == GLUT_LEFT_BUTTON)
	{
		if(state == GLUT_DOWN)
		{
			can_move = true;
		}
		else
		{
			can_move = false;
		}
	}
	glutPostRedisplay();
    return;
}

void mouseMove(int x, int y)
{
	Vector mouse(2);
	mouse[0] = x * 10.0 / 640.0 - 5.0;
	mouse[1] = -(y * 10.0 / 640.0 - 5.0);
	if(can_move)
	{
		for(int i=0; i<num_vertex; i++)
		{
			if((mouse - *(nodes[i].position)).norm() < 0.3)
			{
				if(nodes[i].fixed)
				{
					*(nodes[i].position) = mouse;
					*(nodes[i].velocity) = 0;
				}
			}
		}
	}
	glutPostRedisplay();
    return;
}

int main(int argc, char** argv) 
{
	if (argc != 2) 
    {
    	printf("Usage:\n");
    	printf("<program_name> <name_of_the_file_without_path>\n");
    	printf("\n");
    	printf("Example:\n");
    	printf("<program_name> test\n");
    	printf("This line will open ../in/test.sim\n");
        exit(1);
    }

    char *path = new char[1024];
    strcpy(path, "../in/");
    strcat(path, argv[1]);
    strcat(path, ".sim");
    printf("Path: %s\n", path);

	initVertices(&nodes, &num_vertex, path, &g, &h, &rigid_bars_count);

	delete[] path;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Simulation");
	glutDisplayFunc(display);
    glutIdleFunc (update);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMove);
	init();
	glutMainLoop();
}