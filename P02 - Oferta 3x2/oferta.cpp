// Daniel Fernandez Ortiz
// PC03
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

const int MAX = 10001;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int libros; cin >> libros;
    if (!cin) return false;
    
    int descuento = 0, minimo = MAX;

    for (int i = 0; i < libros; i++) {
        int x; cin >> x;
        minimo = min(minimo, x);
        if ((i + 1) % 3 == 0) {
            descuento += minimo;
            minimo = MAX;
        } 
    }

    // for (int i = 0; i < libros; i++) {
    //     minimo = min(minimo, precios[i]);
    //     if ((i + 1) % 3 == 0) {
    //         descuento += minimo;
    //         minimo = MAX;
    //     } 
    // }
    
    // set<int>precios;
    // for (int i = 0; i < libros; i++) {
    //     int x; cin >> x;
    //     precios.insert(x);
    // }


    // int descuento = 0, minimo = MAX, cont = 1;

    // for (set<int>::reverse_iterator it = precios.rbegin(); it != precios.rend(); it++) {
    //     minimo = min(minimo, *it);
    //     if (cont == 3) {
    //         descuento += minimo;
    //         minimo = MAX;
    //         cont = 0;
    //     }
    //     cont++;
    // }


    cout << descuento << "\n";

    
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