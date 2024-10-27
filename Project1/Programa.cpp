#include "Programa.h"
Programa::Programa() {
	srand(time(0));
	grafo = new CGrafo<int>();
	matrix = nullptr;
	op = 0;
	n = 0;
	inicial = 0;
	final_ = 0;
}
void Programa::setop(int op) {
	this->op = op;
}
void Programa::menu() {
	while (1) {
		system("cls");
		switch (op) {
		case 1:
			build_matrix();
			create_grafo();
			maxFlujo();
			exit(0);
			break;
		case 2:
			enter_matrix();
			create_grafo();
			maxFlujo();
			exit(0);
			break;
		default:
			break;
		}
	}
}

void Programa::build_matrix() {
	//removeIMG();
	system("cls");
	int menor = 0;
	int probabilidad[] = { 0, 0, 0,1, 2,2,3, 3, 4,4,4, 5,5, 6, 7, 8, 9,8,8,9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
	do {
		std::cout << "Ingresa el tama" << char(164) << "o de tu matrix (n * n):";
		std::cin >> n;
	} while (n < 8 || n > 16);
	matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0 + i; j < n; j++) {
			menor = rand() % 2;
			if (menor == 1) {
				matrix[i][j] = probabilidad[rand() % 35];
				matrix[j][i] = 0;

			}
			else {
				matrix[j][i] = probabilidad[rand() % 35];
				matrix[i][j] = 0;
			}
		}
	}
	buildgraphviz();
	print_matrix();
	Project1::ImgGrafo^ imgrafo = gcnew Project1::ImgGrafo();
	imgrafo->ShowDialog();
	imgrafo->Close();
	imgrafo = nullptr;
	delete imgrafo;
}
void Programa::buildgraphviz() {
	graficador = new Graficador(n);
	graficador->setN(n);
	graficador->generardot(matrix);
	graficador = nullptr;
	delete graficador;
}
void Programa::enter_matrix() {
	_sleep(5000);
	system("cls");
	do {
		std::cout << "Ingresa el tama" << char(164) << "o de tu matrix (n * n):";
		std::cin >> n;
	} while (n < 8 && n > 16);
	matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}
	for (int j = 0; j < n; j++) {
		system("cls");
		for (int i = 0; i < n; i++) {
			if (j != i) {
				std::cout << "Ingresa la capacidad del nodo (" << j << " , " << i << ") :";
				std::cin >> matrix[i][j];
			}
			else {
				matrix[i][j] = 0;
			}
		}
	}
	
	buildgraphviz();
	print_matrix();
	Project1::ImgGrafo^ imgrafo = gcnew Project1::ImgGrafo();
	imgrafo->ShowDialog();
	
}
void Programa::print_matrix() {
	std::cout << "\n----MATRIX FINAL----" << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout <<(matrix[i][j]<10? " ": "") << matrix[i][j] << " ";
		}
		std::cout<<std::endl;
	}
	_getch();
}

void Programa::create_grafo(){
	grafo->clean_graph();
	for (int i = 0; i < n; i++) {
		grafo->adicionarVertice(i);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] != 0) {//y x
				grafo->adicionarArco(i,j);
				grafo->modificarArco(i, grafo->cantidadArcos(i) - 1, matrix[i][j]);
			}
		}
	}
	_getch();
}
bool Programa::breadthsearchfirst(int **rGraph) {
	queue<int> cola;
	rutamascorta = new int[n];
	bool* Visitados = new bool[n];
	for (int i = 0; i < n; i++) {
		Visitados[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		rutamascorta[i] = 0;
	}
	cola.push(inicial);
	Visitados[inicial] = 1;
	rutamascorta[inicial] = -1;


	while (!cola.empty()) {
		int u = cola.front();
		cola.pop();

		for (int v = 0; v < n; v++) {
			if (Visitados[v] == false && rGraph[u][v] > 0) {

				if (v == final_) {
					rutamascorta[v] = u;
					return 1;
				}
				cola.push(v);
				rutamascorta[v] = u;
				Visitados[v] = 1;
			}
		}
	}

	return 0;
}
int Programa::fordFulkerson() {
	 int u, v;
 
    int **residualGraph = new int*[n];
	for (int i = 0; i < n; i++) {
		residualGraph[i] = new int[n];
	}
	for (u = 0; u < n; u++)
		for (v = 0; v < n; v++)
			residualGraph[u][v] = matrix[u][v];
 
 
    int max_flow = 0; 
 
    while (breadthsearchfirst(residualGraph)) {

        int path_flow = INT_MAX;
        for (v = final_; v != inicial; v = rutamascorta[v]) {
            u = rutamascorta[v];
            path_flow = min(path_flow, residualGraph[u][v]);
        }
 
        for (v = final_; v != inicial; v = rutamascorta[v]) {
            u = rutamascorta[v];
            residualGraph[u][v] -= path_flow;
			residualGraph[v][u] += path_flow;
        }
 
        max_flow += path_flow;
    }
 
    return max_flow;
}
void Programa::maxFlujo() {
	system("cls");
	print_matrix();
	std::cout << "Los vertices a ingresar son: ";
	for (int i = 0; i < n; i++) {
		std::cout << i << " ";
	}
	std::cout << "\n--------- Flujo Maximo con Ford-Fulkerson --------";
	std::cout << "\nIngresa el numero del que deseas tomar como nodo inicial: ";
	std::cin >> inicial;
	std::cout << "\nIngresa el numero del que deseas tomar como nodo de llegada: ";
	std::cin >> final_;

	std::cout << "\nEl flujo maximo de este grafo es " << fordFulkerson();
	_getch();
}