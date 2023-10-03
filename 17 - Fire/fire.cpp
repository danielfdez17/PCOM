// Alex Bonilla Taco y Daniel Fernandez Ortiz
// PC03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
using namespace std;

struct tcasilla {
    int fila, columna, movimientos;
};

const int MAX = 1000;
int tablero[MAX][MAX];
bool visitados[MAX][MAX];
int R, C;
queue<tcasilla>cola;

int movimientos[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    cin >> R >> C;
    tcasilla joe, fire;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> tablero[i][j];
            if (tablero[i][j] == 'J') {
                joe.fila = i; joe.columna = j; joe.movimientos = 0;
            }
            else if (tablero[i][j] == 'F') {
                fire.fila = i; fire.columna = j; fire.movimientos = 0;
            }
        }
    }
    
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}