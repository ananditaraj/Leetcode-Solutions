const int mod = 1e9 + 7;
using int2 = pair<unsigned long long, int>;
vector<int2> adj[200];

class Solution {
public:
    unsigned long long dijkstra(int start, int n, unsigned long long* dist) {
        unsigned long long way[n];
        priority_queue<int2, vector<int2>, greater<int2>> pq;
        pq.emplace(0, start);
        dist[start] = 0, way[start] = 1;

        while (!pq.empty()) {
            auto [d0, i] = pq.top();
            pq.pop();
            if (d0 > dist[i]) continue; // Optimization: Skip outdated distances
            
            for (auto [d2, j] : adj[i]) {
                unsigned long long newD = d0 + d2;
                if (newD < dist[j]) {
                    dist[j] = newD, way[j] = way[i];
                    pq.emplace(newD, j);
                } else if (newD == dist[j]) {
                    way[j] = (way[j] + way[i]) % mod;
                }
            }
        }
        return way[n - 1];
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        for (int i = 0; i < n; i++) adj[i].clear();
        for (auto& e : roads) {
            adj[e[0]].emplace_back(e[2], e[1]);
            adj[e[1]].emplace_back(e[2], e[0]);
        }
        unsigned long long dist[200];
        fill(dist, dist + n, ULLONG_MAX);
        return dijkstra(0, n, dist);
    }
};
