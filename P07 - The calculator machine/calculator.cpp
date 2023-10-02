// Daniel Fernandez Ortiz
// PC03
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 10000, RAMAS = 3;

vector<bool>visitados(MAX, false);
vector<int>dist(MAX, 0);

int next(int u, int i) {
    switch(i) {
        case 0: u++; break;
        case 1: u *= 2; break;
        case 2: u /= 3; break;
    }
    return u % MAX;
}

int bfs(int origen, int destino) {
    int teclas_pulsadas = 0;
    queue<int>cola;
    dist[origen] = 0; visitados[origen] = true;
    cola.push(origen);

    while (!cola.empty()) {
        int u = cola.front(); cola.pop();
        for (int i = 0; i < RAMAS; i++) {
            int v = next(u, i);
            if (v == destino) return dist[u] + 1;
            if (!visitados[v]) {
                dist[v] = dist[u] + 1;
                teclas_pulsadas = dist[v];
                visitados[v] = true;
                cola.push(v);
            }
        }
    }

    return teclas_pulsadas;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int origen, destino; cin >> origen >> destino;
    if (!cin) return false;
    
    if (origen == destino) cout << "0\n";
    else cout << bfs(origen, destino) << "\n";

        
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     ifstream in("datos.txt");
     auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect cin to casos.txt
     #endif 
    
    
    while (resuelveCaso());

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}