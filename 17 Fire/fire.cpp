// Alex Bonilla Taco y Daniel Fernandez Ortiz
// PC03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

#define MAX 1000
#define MAX_MOVS 4

struct tcasilla {
    int fila, columna;
    tcasilla() : fila(0), columna(0) {}
    tcasilla(int f, int c) : fila(f), columna(c) {}
};

string tablero[MAX][MAX];
bool joe_visi[MAX][MAX];
bool fire_visi[MAX][MAX];
queue<tcasilla>cola_fuegos;
int R, C;

int movs[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};

bool ok(int r, int c) {
    return 0 <= r && r < R && 0 <= c && c < C;
}

bool exit(int r, int c) {
    return r < 0 || r >= R || c < 0 || c >= C;
}

void mostrar() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << "\n";
    }
}

void bfs_fuego(int f, int c) {
    fire_visi[f][c] = true;
    cola_fuegos.push({f,c});
    int cont = 1;
    while (!cola_fuegos.empty()) {
        tcasilla v = cola_fuegos.front(); cola_fuegos.pop();
        for (int i = 0; i < MAX_MOVS; i++) {
            int nf = v.fila + movs[i][0], nc = v.columna + movs[i][1];
            if (ok(nf,nc) && !fire_visi[nf][nc] && tablero[nf][nc]==".") {
                fire_visi[nf][nc] = true;
                tablero[nf][nc] = to_string(cont);
                cola_fuegos.push({nf,nc});
            }
        }
        cont++;
    }
}

pair<bool, int> bfs(int f, int c) {
    bool quemado = true;
    int pasos = 0;
    queue<tcasilla>cola;
    joe_visi[f][c] = true;
    cola.push({f,c});
    while (!cola.empty()) {
        tcasilla v = cola.front(); cola.pop();
        for (int i = 0; i < MAX_MOVS; i++) {
            int nf = v.fila + movs[i][0], nc = v.columna + movs[i][1];
            if (exit(nf, nc))
                return {true, pasos + 1};
            if (!joe_visi[nf][nc] && tablero[nf][nc]!="#" && tablero[nf][nc]!="F" && to_string(pasos + 1) < tablero[nf][nc]) {
                cola.push({nf,nc});
                pasos++;
                joe_visi[nf][nc] = true;
            }
        }
    }
    return {!quemado, pasos};
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    cin >> R >> C;
    tcasilla joe, fire;
    memset(joe_visi, 0, sizeof(joe_visi));
    memset(fire_visi, 0, sizeof(fire_visi));


    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char c; cin >> c;
            tablero[i][j] = c;
            if (tablero[i][j] == "J") {
                joe.fila = i; joe.columna = j;
            }
            else if (tablero[i][j] == "F") {
                cola_fuegos.push({i, j});
            }
        }
    }
    fire = cola_fuegos.front(); cola_fuegos.pop();
    bfs_fuego(fire.fila, fire.columna);
    pair<bool, int>p = bfs(joe.fila, joe.columna);
    // mostrar();
    cout << (p.first ? to_string(p.second) : "IMPOSSIBLE") << "\n";
    
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