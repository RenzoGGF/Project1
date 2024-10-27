#pragma once
#include"Dependencies.h"
class Graficador{
public:
	Graficador(int n);
	string graficar(int **matrix);
	string getDirectoryPath();
	void generardot(int** matrix);
	void setN(int n);
private:
	string ruta;
	int n;
};

