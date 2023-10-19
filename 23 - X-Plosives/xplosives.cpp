// Daniel Fernandez Ortiz
// PC03
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

#define MAX_SIZE 1e6

using arista = pair<int , pair<int, int>>;

struct UFDS {
    vector<int>p;
    int numSets;
    UFDS(int n) : p(MAX_SIZE, 0), numSets(n) {
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int find(int x) {
        return (p[x] == x) ? x : p[x] = find(p[x]);
    } 
    void merge(int x, int y) {
        int i = find(x), j = find(y);
        if (i == j) return;
        p[i] = j;
        numSets--;
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int a, b; cin >> a;
    if (!cin) return false;

    int vertices = 1, A = 0;
    vector<arista> aristas;
    while (a != -1) {
        cin >> b;
        aristas.push_back({1, {a - 1, b - 1}});
        ++A;
        ++vertices;
        cin >> a;
    }

    int coste = 0;
    UFDS uf(vertices);
    for (auto ar : aristas) {
        if (uf.find(ar.second.first) != uf.find(ar.second.second)) {
            uf.merge(ar.second.first, ar.second.second);
            coste += ar.first;
            if (uf.numSets == 1) break;
        }
    }

    cout << A - coste << "\n";
    
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