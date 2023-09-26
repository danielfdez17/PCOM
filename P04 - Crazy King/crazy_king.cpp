// Daniel Fernandez Ortiz
// PC03
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 100, MOVS = 8;

// {fila, columna}
int mov_caballo[8][2] = {{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2}};
int mov_rey[8][2] = {{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};

char tablero[MAX][MAX];
bool visitadas[MAX][MAX];

int M, N, L = 0;

pair<int, int> comienzo, fin;

bool ok(int i, int j) {
    return 0 <= i && i < M && 0 <= j && j < N;
}

void eliminar_casillas(int fila, int columna) {
    for (int i = 0; i < MOVS; i++) {
        int f = fila + mov_caballo[i][0], c = columna + mov_caballo[i][1];
        if (ok(f, c) && tablero[f][c] == '.') tablero[f][c] = '-';
    }
}

void mostrar_tablero() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            cout << tablero[i][j] << " ";
        cout << "\n";
    }
}

struct tcasilla {
    pair<int, int>pos;
    int movimientos;
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> tablero[i][j];
            if (tablero[i][j] == 'A') comienzo = {i, j};
            else if (tablero[i][j] == 'B') fin = {i, j};
            visitadas[i][j] = false;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (tablero[i][j] == 'Z') eliminar_casillas(i, j);
        }
    }

    //mostrar_tablero();
    
    bool found = false;
    queue<tcasilla>q;

    q.push({comienzo, 0});
    while (!q.empty()) {
        tcasilla aux = q.front(); q.pop();
        if (tablero[aux.pos.first][aux.pos.second] == 'B') {
            found = true;
            L = aux.movimientos;
            break;
        }
        else {
            // Se recorren todos los movimientos posibles
            for (int i = 0; i < MOVS; i++) {
                int f = aux.pos.first + mov_rey[i][0], c = aux.pos.second + mov_rey[i][1];
                if (ok(f, c) && !visitadas[f][c] && (tablero[f][c] == '.' || tablero[f][c] == 'B')) {
                    visitadas[f][c] = true;
                    q.push({{f, c}, aux.movimientos + 1});
                }
            }
        }
    }

    cout << (found ? "Minimal possible length of a trip is " + to_string(L) :
        "King Peter, you can't go now!") << "\n";
    
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
