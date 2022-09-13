
#include<stdlib.h> 
#include<glut.h>
#include<gl/GLU.h>
#include<time.h> 
#include<string.h> 
#include<stdio.h> 

int win1, win2;
void Write(float x, float y, float z, float scale, char* s)
{
	int i, l = strlen(s);
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(scale, scale, scale);
	for (i = 0; i < l; i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, s[i]);
	glPopMatrix();
}

void frontsheet(void)
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	Write(-1, 0.9, 1, 0.0007, (char*)"Thapar Institute Of Engineering Technology");
	Write(-0.5, 0.8, 1, 0.0006, (char*)"    CSED    ");
	glColor3f(1.0, 0.0, 0.0);
	Write(-0.45, 0.6, 0.0, 0.0007, (char*)"   FLY HIGH");
	glColor3f(1.0, 0.5, 0.0);
	Write(-0.4, -0.8, 0.0, 0.0006, (char*)"Press 'C' to continue");
	glColor3f(0, 0, 1.0);
	Write(-1.0, 0.1, 0.0, 0.0007, (char*)" Submitted By:");
	glColor3f(0.0, 0.0, 0.0);
	Write(-1.0, -0.03, 0.0, 0.0006, (char*)"1. Yogesh Sharma:  101903237");
	Write(-1.0, -0.13, 0.0, 0.0006, (char*)"2. Tarush Srivastava: 102083060");
	Write(-1.0, -0.23, 0.0, 0.0006, (char*)"3. Anurag Kapoor:  101903225");
	glFlush();
}

float bspd = 0.01;
float b1x = 50.0, b1y = 0;
float hm = 0.0;
int i = 0, sci = 1; float scf = 1;
char scs[20], slevel[20];
int level = 1, lflag = 1, wflag = 1;

void init(void)
{
	srand(time(0));
	b1y = (rand() % 45) + 10;
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, .0);
}

void drawcopter()
{
	glColor3f(1.0, 0.5, 0.3);
	glRectf(10, 49.8, 19.8, 44.8);
	glRectf(2, 46, 10, 48);
	glRectf(2, 46, 4, 51);
	glRectf(14, 49.8, 15.8, 52.2);
	glRectf(7, 53.6, 22.8, 52.2);
}

void renderBitmapString(float x, float y, float z, void* font, const char* string)
{
	const char* c;
	glRasterPos2f(x, y);
	glColor3f(1, 0, 0);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	if ((i == 730 || i == -700)

		||
		(((int)b1x == 10 || (int)b1x == 7 || (int)b1x == 4 || (int)b1x == 1) && (int)b1y < 53 + (int)hm && (int)b1y + 35>53 + (int)hm)

		||
		(((int)b1x == 9 || (int)b1x == 3 || (int)b1x == 6) && (int)b1y < 45 + (int)hm && (int)b1y + 35>45 + (int)hm)

		||
		(((int)b1x == 0) && (int)b1y < 46 + (int)hm && (int)b1y + 35>46 + (int)hm))
	{
		glColor3f(0.0, 0.0, 0.0);
		glRectf(0.0, 0.0, 100.0, 100.0);
		glColor3f(1.0, 0.0, 0.0);
		renderBitmapString(41, 70, 0, GLUT_BITMAP_HELVETICA_18, "GAME OVER!!!");
		glColor3f(1.0, 1.0, 1.0);
		renderBitmapString(25, 60, 0, GLUT_BITMAP_TIMES_ROMAN_24, "THANKS FOR PLAYING THE GAME!!\n");
		renderBitmapString(40, 50, 0, GLUT_BITMAP_TIMES_ROMAN_24, "Your Score:");
		renderBitmapString(55, 50, 0, GLUT_BITMAP_TIMES_ROMAN_24, scs);
		glutSwapBuffers();
		glFlush();
		printf("\nGAME OVER\n\n");
		printf("You scored  %s", scs);
		system("pause");

		printf("\n\nClose the console window to exit...\n");
		exit(0);
	}

	else
	{
		if (sci % 50 == 0 && lflag == 1)
		{
			lflag = 0;
			level++;
			bspd += 0.005;
		}

		else if (sci % 50 != 0 && lflag != 1)
		{
			lflag = 1;
		}
		glPushMatrix();
		glColor3f(0.0, 0.5, 0.7);
		glRectf(0.0, 0.0, 100.0, 10.0);
		glRectf(0.0, 100.0, 100.0, 90.0);
		glColor3f(1.0, 0.0, 0.0);

		sprintf_s(slevel, "%d", level);
		renderBitmapString(10, 92, 0, GLUT_BITMAP_TIMES_ROMAN_24, "Level:");
		renderBitmapString(20, 92, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, slevel);

		scf += 0.01;
		sci = (int)scf;
		sprintf_s(scs, "%d", sci);
		renderBitmapString(60, 92, 0, GLUT_BITMAP_TIMES_ROMAN_24, "Score:");
		renderBitmapString(70, 92, 0, GLUT_BITMAP_TIMES_ROMAN_24, scs);
		glTranslatef(0.0, hm, 0.0);
		drawcopter();

		if (b1x < -10)
		{
			b1x = 50;            //total width is 50 
			b1y = (rand() % 25) + 10;
		}

		else
			b1x -= bspd;

		glTranslatef(b1x, -hm, 0.0);
		glColor3f(0.7, 0.0, 1.0); 
		glRectf(b1x, b1y, b1x + 5, b1y + 35);
		glPopMatrix();
		glutSwapBuffers();
		glFlush();
	}
}

void moveHeliU(void)
{

	hm += 0.05;
	i++;
	glutPostRedisplay();

}

void moveHeliD()
{

	hm -= 0.05;
	i--;
	glutPostRedisplay();

}

void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:

		if (state == GLUT_DOWN)
			glutIdleFunc(moveHeliU);

		else if (state == GLUT_UP)
			glutIdleFunc(moveHeliD);
		break;
	default: break;
	}
}

void keys(unsigned char key, int x, int y)
{
	if (key == 'w') glutIdleFunc(moveHeliU);
	if (key == 'm') glutIdleFunc(moveHeliD);
}

void keyboards(unsigned char key, int x4, int y4)
{
	if (key == 'c' || key == 'C')
	{
		glutDestroyWindow(win1);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
		win2 = glutCreateWindow("FLY HIGH");
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glFlush();
		glutDisplayFunc(display);
		gluOrtho2D(-1000, 1000, 0, 1000);
		init();
		glutMouseFunc(mouse);
		glutKeyboardFunc(keys);
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(200, 200);
	win1 = glutCreateWindow("FLY HIGH");
	glFlush();
	glutDisplayFunc(frontsheet);
	glutKeyboardFunc(keyboards);
	glutMainLoop();
	return 0;
}