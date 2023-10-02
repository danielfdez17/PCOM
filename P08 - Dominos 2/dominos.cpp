// Daniel Fernandez Ortiz
// PC03
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 10000;

queue<int>cola;
vector<bool>visitados(MAX, false);
vector<int>dist(MAX, 0);

int bfs(int u) {
    int fichas_caidas = 0;
    cola.push(u); visitados[u] = true;
    while (!cola.empty()) {
        int v = cola.front(); cola.pop();
        if (!visitados[v]) {
            visitados[v] = true;
            dist[v] = dist[u] + 1;
            fichas_caidas++;
            cola.push(v);
        }
    }
    return fichas_caidas;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    int n, m, l; cin >> n >> m >> l;
    for (int i = 0; i < m; i++) {
        
    }
    for (int i = 0; i < l; i++) {
        int x; cin >> x; 
        cola.push(x);
        visitados[x] = true;
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