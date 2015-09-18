#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include "Retangulo.h"

const int X = 32;
const int Y = 32;

using namespace std; //para dizer que não precisa colocar namespace na frente do objeto criado por ela

Retangulo matrix[X][Y];
int rPrimeira;
int gPrimeira;
int bPrimeira;
int percentual = 8;
int pontos = 0;
int tentativas = 0;
int maxTentativas = 32;

void checkRetangulo(int x, int y){
	if(matrix[x][y] == false){
	matrix[x][y].setRed(0);
	matrix[x][y].setGreen(0);
	matrix[x][y].setBlue(0);
	glutPostRedisplay();
	}
}

void drawRect(float x, float y, float weight, float height, int r, int g, int b) {
	glColor3ub(r, g, b);
	printf("Drawing...");
	glBegin(GL_QUADS);
	glVertex2f(x + weight, y - height);
	glVertex2f(x + 2 + weight, y - height);
	glVertex2f(x + 2 + weight, y - 2 - height);
	glVertex2f(x + weight, y - 2 - height);
	glEnd();
	//glutSwapBuffers();
}

float calcula(float r1, float g1, float b1, float r2, float g2, float b2){
	resultadoC = sqrt(pow(r1-r2, 2.0) + pow(g1-g2, 2.0) + pow(b1-b2, 2.0));
	return resultadoC;
}

void mouse(int button, int state, int x, int y) {
if (button == 0 && state == 0 && tentativas < maxTentativas){
		verificaCores(x, y);
		tentativas += 1;
		printf("Pontos: %d\n", pontos);
	}
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
}
void display(void) {
	//glutSwapBuffers();
	float xx = 2;  //x inicial da tela
	float yy = 2; // y inicial da tela
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < X; i++) {
		xx = 0; // volta para o 0, para começar nova linha
		for (int j = 0; j < Y; j++) {
			int r = matrix[i][j].getRed();
			int g = matrix[i][j].getGreen();
			int b = matrix[i][j].getBlue();
			bool v = ret[i][j].isVisivel();
			if (v == true){
				glColor3f(r, g, b);
			}
			else{
				glColor3f(1, 1, 1);
			}
			drawRect(-34, 34, xx, yy, r, g, b);
			xx += 2;
		}
		yy += 2;
	}
	glutSwapBuffers();
	//glFlush();
}

void verificaCores(int x, int y){

	int iT = y / 18.75;
	int jT = x / 25;
	if (ret[iT][jT].isVisivel() == true) {
		printf("Posicao do array: ret[%d][%d]\n", iT, jT);

		rPrimeira = ret[iT][jT].getRed();
		gPrimeira = ret[iT][jT].getGreen();
		bPrimeira = ret[iT][jT].getBlue();

		for (int i = 0; i < X; i++){
			for (int j = 0; j < Y; j++){
				int rSegunda = ret[i][j].getRed();
				int gSegunda = ret[i][j].getGreen();
				int bSegunda = ret[i][j].getBlue();

				double raiz = (rPrimeira - rSegunda) * (rPrimeira - rSegunda);
				raiz += (gPrimeira - gSegunda) * (gPrimeira - gSegunda);
				raiz += (bPrimeira - bSegunda) * (bPrimeira - bSegunda);

				raiz = sqrt(raiz);

				double distancia = (percentual * 441.67) / 100;

				if (raiz < distancia){
					ret[i][j].setVisivel(false);
					pontos += 1;
				}
			}
		}
		glutPostRedisplay();
	}
	else{
		printf("Retangulo clicado nao esta visivel!");
		tentativas -= 1;
	}
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
	// inicialização da GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Jogo das Cores");
	init();
	// funções de call-back para a GLUT. Devemos passar o nome da função que
	// criamos para a GLUT. Os parâmetros estar no padrão (veja slides)
	glutDisplayFunc(display); // função de desenho
	glutReshapeFunc(reshape); // tratamento de redimensionamento da janela
	glutMouseFunc(mouse); // tratamento de mouse
						  // inicializações do programa
	init();
	// Inicia loop do programa, o main loop
	glutMainLoop();
	return 0;
}
