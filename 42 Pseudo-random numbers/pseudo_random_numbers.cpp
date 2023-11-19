// Daniel Fernandez Ortiz
// PC03
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <unordered_set>
using namespace std;
#define MAX 10000
int cases = 1;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int z, i, m, l; cin >> z >> i >> m >> l;
    if (z == 0 && i == 0 && m == 0 && l == 0) return false;
    int first_random = l;
    int next, sequence = 0;
    // unordered_set<int>visitados;
    // visitados.clear();
    bool visited[MAX];
    memset(visited, 0, MAX * sizeof(bool));
    visited[l] = true;
    // while (next != first_random && visitados.count(next) == 0) {
    //     visitados.insert(next);
    //     // next = (z * l + i) % m;
    //     l = next;
    //     ++sequence;
    // }
    // if (next == first_random) ++sequence;
    while (true) {
        // next = (z * l + i) % m;
        long long prod = ((z % m) * (l % m)) % m;
        next = ((prod % m) + (i % m)) % m;
        if (next == first_random) {
            sequence++;
            break;
        }
        else if (visited[next]) break;
        // else if (visitados.count(next) != 0) {
        //     break;
        // }
        l = next;
        visited[next] = true;
        // visitados.insert(next);
        sequence++;
    }
    cout << "Case " << cases << ": " << sequence << "\n";
    cases++;
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
