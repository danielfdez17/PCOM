﻿// ALEX BONILLA y DANIEL
// PC03


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_T = 1000;
string tablero[MAX_T][MAX_T];
queue<pair<int, int>>joe, fire;

bool transitable[MAX_T][MAX_T];

const int MOVS = 4;
int movs[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
int r, c;
bool ok(int x, int y) {
    return 0 <= x && x < r && 0 <= y && y < c;
}

struct tcasilla {
    int fila, columna;
    tcasilla() : fila(0), columna(0) {}
    tcasilla(int f, int c) : fila(f), columna(c) {}
    tcasilla(pair<int, int>q) : fila(q.first), columna(q.second) {}
};



// función que resuelve el problema
int GetTime(queue<pair<int,int>>&fire, queue<pair<int, int>>& joe) {
    int turn = 1;
    while (!joe.empty()) {
        queue<pair<int, int>>qTem;
        while (!fire.empty()){
            tcasilla casilla(fire.front());
            fire.pop();
            for (int i = 0; i < MOVS; i++) {
                int nf = casilla.fila + movs[i][0], nc = casilla.columna + movs[i][1];
                if (ok(nf, nc) && transitable[nf][nc])
                {
                    transitable[nf][nc] = false;
                    qTem.push(make_pair(nf, nc));
                }
            }
            

        }
        fire.swap(qTem);
        
        while (!joe.empty())
        {
            tcasilla pos(joe.front()); joe.pop();
            for (int i = 0; i < MOVS; i++) {
                int nf = pos.fila + movs[i][0], nc = pos.columna + movs[i][1];
                if (transitable[nf][nc]&&ok(nf, nc) ) qTem.push(make_pair(nf, nc));
                
                else if (!ok(nf, nc) && !transitable[nf][nc]) {
                    
                    return turn;

                }

                
            }
        }

        joe.swap(qTem);
        

        ++turn;
    }
    return -1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
   
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char letra;
            cin >> letra;
            tablero[i][j] = letra;
            transitable[i][j] = false;
            if (tablero[i][j] == "J") {
                joe.push(make_pair(i,j));
                transitable[i][j] = true;
            }
            else if (tablero[i][j] == "F") {
                fire.push(make_pair(i, j));
            }
            else if (tablero[i][j] == ".") transitable[i][j] = true;
        }

    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << "\n";
    }
    /*
    * //ver matriz de transitable
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (transitable[i][j])
                cout << "T "; else cout << "F ";
        }
        cout << "\n";
    }
    */
  /* TipoSolucion sol = resolver(datos);*/
    // escribir sol
    
    int time = GetTime(fire,joe);
    if (time == -1)
        cout << "IMPOSSIBLE\n";
    else
        cout << time << '\n';

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