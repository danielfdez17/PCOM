// Daniel Fernandez Ortiz y Alex Bonilla Taco
// PC03
#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <map>
#include <vector>
#include <queue>
using namespace std;

map<string, vector<string>>grafo;
map<string, bool>visitados;
// pair<origen, destino>
map<string, string>ruta;
string origen, destino;

void bfs() {
    queue<string>cola;
    cola.push(origen);
    visitados[origen] = true;
    while(!cola.empty()) {
        string front = cola.front(); cola.pop();
        if (front != destino) {
            int size = grafo[front].size();
            for (int i = 0; i < size; i++) {
                string v = grafo[front][i];
                if (!visitados[v]) {         
                    visitados[v] = true; 
                    ruta[v] = front;               
                    cola.push(v);
                }
            }
        }

          
            
    }
}
void printpath(string a, string b) {
    if (a == b) { return; }
    printpath(ruta[a], b);
    cout << ruta[a] << " " << a << endl;;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; cin >> n;
    if (!cin) return false;

    grafo.clear();
    visitados.clear();

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    cin >> origen >> destino;

    if(origen==destino) cout << origen << " " << destino << "\n";
    else {
        bfs();
        if (!visitados[destino]) cout << "No route\n";
        else {
            printpath(destino, origen);
           /* while (destino != origen) {
                string aux;
                cout << ruta[destino] << " " << destino << endl;
                destino = ruta[destino];
                aux = ruta[destino];
            }*/
           

        }
    }
    cout << "\n";

    
    
    // escribir sol
    
    
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