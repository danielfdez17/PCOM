// Daniel Fernandez Ortiz
// PC03
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n; cin >> n;
    if (n == 0) return false;
    
    int c1, n1, c2, n2; cin >> c1 >> n1 >> c2 >> n2;
    int m1 = 0, m2 = 0;
    if (c1 < c2) {
        while (n > n1) {
            ++m1;
            n -= n1;
        }
        while (n > n2) {
            ++m2;
            n -= n2;
        }
        if (n != 0) ++m2;
    }
    else {
        while (n > n2) {
            ++m2;
            n -= n2;
        }
        while (n > n1) {
            ++m1;
            n -= n1;
        }
        if (n != 0) ++m1;
    }

    if (m1 == 0 && m2 == 0) cout << "failed\n";
    else cout << m1 << " " << m2 << "\n";

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