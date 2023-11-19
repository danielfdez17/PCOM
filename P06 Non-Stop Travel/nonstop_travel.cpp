// Daniel Fernandez Ortiz
// PC03
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 1000000000
#define NI 10

using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvii = vector<vii>;

int cases = 1;
int adjMat[NI + 1][NI + 1];
int camino[NI + 1][NI + 1];
int ni;
vvii adjList(NI, vector<ii>());

// void floyd() {
//     for (int k = 0; k < ni; ++k) {
//         for (int i = 0; i < ni; ++i) {
//             for (int j = 0; j < ni; ++j) {
//                 int best = adjMat[i][k] + adjMat[k][j];
//                 int current = adjMat[i][j];
//                 if (best < current) {
//                     // cout << "From " << i + 1 << " to " << j + 1 << " throughout " << k + 1 << " with cost: " << best << "\n";
//                     adjMat[i][j] = best;
//                     camino[i][j] = k;
//                 }
//             }
//         }
//     }
// }


void dijkstra(int s, vi&dist, vi&camino, int t) {
    dist.assign(adjList.size(), INF);
    dist[s] = 0; camino.push_back(s);
    vector<bool>visitados(ni, false);
    visitados[s] = true;
    priority_queue<ii, vii, greater<ii>>pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (u == t) {
            camino.push_back(t);
            return;
        }
        if (d > dist[u]) continue;
        for (auto a : adjList[u]) {
            if (dist[u] + a.first < dist[a.second]) {
                dist[a.second] = dist[u] + a.first;
                pq.push({dist[a.second], a.second});
                if (!visitados[a.second]) {
                    camino.push_back(a.second);
                    visitados[a.second] = true;
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

    for (auto i : adjList) i.clear();

    // for (int i = 0; i < ni; ++i) 
    //     for (int j = 0; j < ni; ++j) {
    //         adjMat[i][j] = INF;
    //         camino[i][j] = 0;
    //     }
    
    for (int i = 0; i < ni; ++i) {
        int streets; cin >> streets;
        for (int j = 0; j < streets; ++j) {
            int next, delay; cin >> next >> delay;
            adjList[i].push_back({delay, next - 1});
            // adjMat[i][next - 1] = delay;
        }
    }

    int source, destiny; cin >> source >> destiny;
    vi dist, camino;
    dijkstra(source - 1, dist, camino, destiny - 1);
    
    // floyd();
    cout << "Case " << cases << ": Path = "; 
    // // TODO
    for (auto i : camino) cout << i + 1 << " ";
    // cout << source << " ";
    // for (int i = camino[source - 1][destiny - 1]; i < destiny - 1; ++i) 
    //     cout << camino[i][destiny - 1] + 1 << " ";
    // cout << destiny;
    // // TODO
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
