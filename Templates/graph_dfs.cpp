#include<iostream>
#include<vector>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vvi adjList;
int V, E;
vector<bool>visited;

int dfs(int v) { // O(V + E)
    int size = 1;
    visited[v] = true;
    for (int w : adjList[v]) 
        if (!visited[w])
            size += dfs(w);
    return size;
}

int main() {

    cin >> V >> E;

    for (int i = 0; i <E; i++) {
        int a, b; cin >> a >> b;
        adjList[a - 1].push_back(b - 1);
        adjList[b - 1].push_back(a - 1);
    }

    visited = vector<bool>(V, false);

    int size = 0;
    for (int i = 0; i < V; i++) 
        if (!visited[i])
            size += dfs(i);

    cout << size << "\n";

    return 0;
}