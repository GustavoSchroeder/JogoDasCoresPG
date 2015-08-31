#pragma once

#include<Windows.h>
#include <stdlib.h>
#include <cstdio>
#include "Retangulo.h"

using namespace std;

void Retangulo::iniciaRetangulo(bool v, int r, int g, int b) {
	visivel = v;
	red = r;
	green = g;
	blue = b;
}

	bool Retangulo::isVisivel() {
		return visivel;
	}
	
	void Retangulo::setVisivel(bool v) {
		visivel = v;
	}
	
	void Retangulo::setRed(int r) {
		red = r;
	}
	
	void Retangulo::setGreen(int g) {
		gree = g;
	}
	
	void Retangulo::setBlue(int b) {
		blue = b;
	}
	
	int Retangulo::getRed() {
		return red;
	}

	int Retangulo::getGreen() {
		return green;
	}

	int Retangulo::getBlue() {
		return blue;
	}

	
