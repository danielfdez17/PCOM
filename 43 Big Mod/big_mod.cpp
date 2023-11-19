// Alex Bonilla Taco y Daniel Fernandez Ortiz
// PC03
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    long long b, p, m; cin >> b >> p >> m;
    if (!cin) return false;

    long long res = 1;
    b %= m;
    while (p > 0) {
        if (p % 2 == 1) res = ((res % m) * (b % m)) % m;
        p = p >> 1;
        b = ((b % m) * (b % m)) % m;
    }

    // int i = 1;
    // int res = b;
    // while (i <= p) {
    //     res = ((res % m) * (b % m)) % m;
    //     i += b;
    // }
    cout << res << "\n";
    
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