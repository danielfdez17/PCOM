#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vvi adjList;
vi dist;
int V, E;
vector<bool>visited;

void bfs(int s) {
    queue<int>q;
    dist[s] = 0;
    visited[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int w : adjList[v]) 
            if (!visited[w]) {
                visited[w] = true;
                dist[w] = dist[v] + 1;
                q.push(w);
            }
    }
}

int main() {

    cin >> V >> E;

    for (int i = 0; i <E; i++) {
        int a, b; cin >> a >> b;
        adjList[a - 1].push_back(b - 1);
        adjList[b - 1].push_back(a - 1);
    }

    visited = vector<bool>(V, false);

    for (int i = 0; i < V; i++) 
        if (!visited[i])
            bfs(i);

    for (int i = 0; i < dist.size(); i++) cout << i + 1 << ": " << dist[i] << "\n"; cout << "\n";
    
    return 0;
}