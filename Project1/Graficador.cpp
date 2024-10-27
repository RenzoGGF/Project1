#include "Graficador.h"

Graficador::Graficador(int n){
    this->n = n;
}
std::string Graficador::graficar(int **matrix) { //
    std::ostringstream oss; // Usamos ostringstream para construir el string

    // Encabezado del archivo DOT
    oss << "digraph G {\n";

    // Iterar sobre la matriz de adyacencia
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Si hay un arco de i a j
            if (matrix[i][j] > 0) {
                // Agregar el arco con el peso correspondiente
                oss << "    " << static_cast<char>('A' + i) << " -> "
                    << static_cast<char>('A' + j) << " [label=\""
                    << matrix[i][j] << "\"];\n";
            }
        }
    }

    // Cierre del archivo DOT
    oss << "}\n";

    return oss.str();
}
std::string Graficador::getDirectoryPath() {
    // Usa __FILE__ directamente
    std::string filePath = __FILE__;

    // Encuentra la posición del último separador de directorio
    size_t lastSlash = filePath.find_last_of("\\");

    // Si encuentra un separador, toma la subcadena hasta ese punto
    if (lastSlash != std::string::npos) {
        return filePath.substr(0, lastSlash);
    }

    return filePath; // Si no encuentra un separador, devuelve la ruta original
}
void Graficador::generardot(int** matrix) {
    std::string rutaGrafo = getDirectoryPath() + "\\grafo.dot"; 
    std::string rutaImagen = getDirectoryPath() + "\\grafo.png";
    std::string comando = "cmd /c start /min cmd /c \"dot -Tpng \"" + rutaGrafo + "\" -o \"" + rutaImagen + "\"\"";
    
    // Convertir el contenido del flujo a un string
    std::string graf = graficar(matrix);
    ofstream archivo(rutaGrafo);
    archivo << graf;
    archivo.close();
    system(comando.c_str());
}

void Graficador::setN(int n) {
    this->n = n;
}