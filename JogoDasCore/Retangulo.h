#pragma once

class Retangulo
{
	bool visivel;
	int red;
	int green;
	int blue;

public:
	void iniciaRetangulo(bool v, int r, int g, int b);
	bool isVisivel();
	int getRed();
	int getGreen();
	int getBlue();
	void setRed(int r);
	void setGreen(int g);
	void setBlue(int b);
	void setVisivel(bool v);

};
