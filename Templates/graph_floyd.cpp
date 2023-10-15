#include<iostream>
using namespace std;

#define MAX 100

int V, E;
int path[MAX][MAX];
int adjMat[MAX][MAX];

void floyd() { // O(V^3)
    for (int k = 0; k < V; k++) 
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++) {
                int aux = adjMat[i][k] + adjMat[k][j];
                if (aux < adjMat[i][j]) {
                    adjMat[i][j] = aux;
                    path[i][k] = k;
                }
            }
}

int main() {

    return 0;
}