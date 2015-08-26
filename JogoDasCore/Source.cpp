#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include "Retangulo.h"

const int x = 32;
const int y = 32;

using namespace std; //para dizer que n�o precisa colocar namespace na frente do objeto criado por ela

Retangulo matrix[32][32];


void drawRect(float x, float y, float weight, float height, int r, int g, int b) {
	glColor3ub(r, g, b);
	printf("Drawing...");
	glBegin(GL_QUADS);
	glVertex2f(x + weight, y - height);
	glVertex2f(x + 2 + weight, y - height);
	glVertex2f(x + 2 + weight, y - 2 - height);
	glVertex2f(x + weight, y -2 - height);
	glEnd();
	//glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
}

void display(void) {
	//glutSwapBuffers();
	float xx = 2;  //x inicial da tela
	float yy = 2; // y inicial da tela
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < x; i++) {
		xx = 0; // volta para o 0, para come�ar nova linha
		for (int j = 0; j < y; j++){
		int r = matrix[i][j].getRed();
		int g = matrix[i][j].getGreen();
		int b = matrix[i][j].getBlue();
			drawRect(-32, 32,  xx,  yy, r, g, b);
			xx += 2;
		}
		yy += 2;
	}
	glutSwapBuffers();
	//glFlush();
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	/*  initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-32, 32, -32, 32);
	glViewport(350, 350, 500, 500); // define pos e tamanho janela
	
	srand((unsigned)time(NULL));
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			float r = rand() % 256;
			float g = rand() % 256;
			float b = rand() % 256;
			matrix[i][j].iniciaRetangulo(true, r, g, b);
		}
	}
}

int main(int argc, char** argv)
{
	// inicializa��o da GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Jogo das Cores");
	init();
	// fun��es de call-back para a GLUT. Devemos passar o nome da fun��o que
	// criamos para a GLUT. Os par�metros estar no padr�o (veja slides)
	glutDisplayFunc(display); // fun��o de desenho
	glutReshapeFunc(reshape); // tratamento de redimensionamento da janela
	//glutMouseFunc(mouse); // tratamento de mouse
						  // inicializa��es do programa
	init();
	// Inicia loop do programa, o main loop
	glutMainLoop();
	return 0;
}