// Daniel Fernandez Ortiz
// PC03
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

#define V 200

using vi = vector<int>;

vi adj[V];
bool visited[V];

int dfs(int v) {
    visited[v] = true;
    int tam = 1;
    for (int w : adj[v]) {
        if (!visited[w]) {
            visited[w] = true;
            tam += dfs(w);
        }
    }
    return tam;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    for (int i = 0; i < V; i++) adj[i].clear();
    memset(visited, 0, sizeof(visited));

    int v, e; cin >> v >> e;
    for (int i = 0; i < e; i++) {

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