#include <bits/stdc++.h>
using namespace std;
#define ll long long 
class dijkstra {
public:
    dijkstra(int n) : n(n), adj(n) {}
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<ll> minDis(int s, vector<int>& path) {
        vector<ll> dist(n, 1e18);
        dist[s] = 0ll;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({0ll, s});
        vector<int> parent(n, -1);
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for (auto [v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
        // Construct path
        int curr = n - 1;
        while (curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());
        return dist;
    }
private:
    int n;
    vector<vector<pair<int, int>>> adj;
};