// Daniel Fernandez Ortiz
// PC03
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000
#define NI 10

int cases = 1;
int adjMat[NI + 1][NI + 1];
int camino[NI + 1][NI + 1];
int ni;

void floyd() {
    for (int k = 0; k < ni; ++k) {
        for (int i = 0; i < ni; ++i) {
            for (int j = 0; j < ni; ++j) {
                int best = adjMat[i][k] + adjMat[k][j];
                int current = adjMat[i][j];
                if (best < current) {
                    // cout << "From " << i + 1 << " to " << j + 1 << " throughout " << k + 1 << " with cost: " << best << "\n";
                    adjMat[i][j] = best;
                    camino[i][j] = k;
                }
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    cin >> ni;
    if (ni == 0) return false;

    for (int i = 0; i < ni; ++i) 
        for (int j = 0; j < ni; ++j) {
            adjMat[i][j] = INF;
            camino[i][j] = 0;
        }
    
    for (int i = 0; i < ni; ++i) {
        int streets; cin >> streets;
        for (int j = 0; j < streets; ++j) {
            int next, delay; cin >> next >> delay;
            adjMat[i][next - 1] = delay;
        }
    }

    int source, destiny; cin >> source >> destiny;
    floyd();
    cout << "Case " << cases << ": Path = "; 
    // TODO
    cout << source << " ";
    for (int i = camino[source - 1][destiny - 1]; i < destiny - 1; ++i) 
        cout << camino[i][destiny - 1] + 1 << " ";
    cout << destiny;
    // TODO
    cout << "; " << adjMat[source - 1][destiny - 1] << " seconds delay\n";
    ++cases;
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
