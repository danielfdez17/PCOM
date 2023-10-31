// Daniel Fernandez Ortiz
// PC03
#include <iostream>
#include <iomanip>
#include <fstream> 
#include <vector> 
using namespace std;

#define MAX_N 100000

int getOne(int x) {
    if (x > 0) return 1;
    else if (x < 0) return -1;
    return x;
}

void showOne(int x) {
    if (x > 0) cout << "+";
    else if (x < 0) cout << "-";
    else cout << "0";
}
class SegmentTree {
private:
    vector<int>st;
    int tam;
    int query(int vertex, int L, int R, int i, int j) {
        if (i > R || j < L) return 0;
        if (L >= i && R <= j) return st[vertex];
        int mitad = (L + R) / 2;
        int q1 = query(vertex * 2, L, mitad, i, j);
        int q2 = query(vertex * 2 + 1, mitad + 1, R, i, j);
        return getOne(getOne(q1) * getOne(q2));
    }
    void update(int vertex, int l, int r, int pos, int newVal) {
        if (pos < l || r < pos) return;
        if (l == r) {
            st[vertex] = newVal;
            return;
        }
        int m = (l + r) / 2;
        if (l <= pos && pos <= m)
            update(vertex * 2, l, m, pos, newVal);
        else
            update(vertex * 2 + 1, m + 1, r, pos, newVal);
        st[vertex] = getOne(getOne(st[vertex * 2] * getOne(st[vertex * 2 + 1])));
        cout << "UPDATE Pos: " << vertex << " " << st[vertex] << "\n";
    }
    void build(int *values, int p, int l, int r) {
        if (l == r) {
            // showOne(values[l]);
            st[p] = getOne(values[l]);
            return;
        }
        int m = (l + r) / 2;
        build(values, 2 * p, l, m);
        build(values, 2 * p + 1, m + 1, r);
        st[p] = getOne(getOne(st[p * 2]) * getOne(st[p * 2 + 1]));
    }
public:
    SegmentTree(int maxN) {
        st.reserve(4 * maxN + 10);
    }
    int query(int a, int b) {
        return query(1, 0, tam - 1, a, b);
    }
    void update(int pos, int newVal) {
        update(1, 0, tam - 1, pos, newVal);
        // showOne(st[pos]);
    }
    void build(int *values, int n) {
        tam = n;
        build(values, 1, 0, n - 1);
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n, k; cin >> n >> k;
    if (!cin) return false;

    SegmentTree segment(n);
    int values[MAX_N];

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        values[i] = getOne(x);
    }
    // cout << "build: ";
    segment.build(values, n);
    // cout << "\n";

    for (int j = 0; j < k; j++) {
        string op; cin >> op;
        if (op == "C") {
            int i, v; cin >> i >> v;
            segment.update(i - 1, getOne(v));
        }
        else {
            int i, i2; cin >> i >> i2;
            showOne(segment.query(i - 1, i2 - 1));
        }
    }

    cout << "\n";
    
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