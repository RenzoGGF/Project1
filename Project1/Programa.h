#pragma once
#include"Dependencies.h"
#include"Graficador.h"
#include"ImgGrafo.h"
class Programa
{
public:
	Programa();
	void menu();
	void setop(int op);
private:
	void buildgraphviz();
	void build_matrix();
	void enter_matrix();
	void print_matrix();
	void create_grafo();
	bool breadthsearchfirst(int** rGraph);
	int fordFulkerson();
	void maxFlujo();
	CGrafo<int>*grafo;
	Graficador* graficador;
	int* rutamascorta;
	int** matrix;
	int inicial;
	int final_;
	int op;
	int n;
};

