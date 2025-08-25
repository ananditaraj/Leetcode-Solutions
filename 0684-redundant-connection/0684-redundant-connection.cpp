class Solution {
public:
    bool dfs(vector<vector<int>> &adj, vector<int> &vis, int n, int par = -1) {
        if (vis[n]) 
        return true;

        vis[n] = 1;
        for (auto i : adj[n]) {
            if (i != par && dfs(adj, vis, i, n)) 
                return true;
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        int n = e.size();
        vector<vector<int>> adj(n + 1); 
        vector<int> vis(n + 1);

        for (auto &edge : e) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);


            fill(vis.begin(), vis.end(), 0);
            if (dfs(adj, vis, u)) 
                return edge;
        }

        return {};
    }
};
