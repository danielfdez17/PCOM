#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define INF 100

vector<vii> adjList;
vi dist;
int V, E;
vector<bool>visited;

void dijkstra(int s, vi &dist) {
    dist.assign(adjList.size(), INF);
    dist[s] = 0;
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        for (auto a : adjList[u]) {
            if (dist[u] + a.first < dist[a.second]) {
                dist[a.second] = dist[u] + a.first;
                pq.push({dist[a.second], a.second});
            }
        }
    }
}




int main() {

    return 0;
}