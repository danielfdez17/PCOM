// Daniel Fernandez Ortiz
// PC03
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
using namespace std;

#define N 200

struct vertice {
    int num, color;
    vector<vertice>adj;
    vertice (int n) : num(n), color(-1) {}
};

using vvertice = vector<vertice>;
vvertice adjList;

bool bicolorable(int v, int color) {
    bool is_bicolorable = true;
    if (adjList[v].color == -1) { // if (!visited[v]) 
        adjList[v].color = color; // visited[v] = true;
        for (vertice w : adjList[adjList[v].num].adj) {
            is_bicolorable = bicolorable(w.num, (color + 1) % 2);
            if (!is_bicolorable) break;
        }
    }
    else {
        if (adjList[v].color != color) 
            is_bicolorable = false;
    }
    return is_bicolorable;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n; cin >> n;
    if (n == 0) return false;
    
    // grafo g = grafo();

    for (auto i : adjList) 
        i.adj.clear();
    adjList.assign(n, {0});

    int l; cin >> l;
    while (l--) {
        int v, w; cin >> v >> w;
        adjList[v].adj.push_back(w);
        adjList[w].adj.push_back(v);
    }

    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (vertice j : adjList[i].adj) 
            cout << j.num << " "; 
        cout << "\n";
    }
    cout << "\n";

    if (!bicolorable(0, 0)) cout << "NOT ";
    cout << "BICOLORABLE\n"; 

    return true;    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso());

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
