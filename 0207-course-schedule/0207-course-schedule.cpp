class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int par, vector<int>& pvis ) {
        vis[node] = 1;
        pvis[node] =1;
        bool ans = true;

        for (auto it : adj[node]) {
            if (pvis[it]) {
                return false;
            } else if (!vis[it]) {
                ans &= dfs(it, adj, vis, node, pvis);
            }
        }
        pvis[node] = 0;
        return ans;
    }
    bool canFinish(int nc, vector<vector<int>>& p) {
        vector<vector<int>> adj(nc);
        vector<int> vis(nc, 0);
        vector<int> pvis(nc, 0);
        bool ans = true;

        for (int i = 0; i < p.size(); i++) {
            int u = p[i][0];
            int v = p[i][1];

            adj[u].push_back(v);
        }
        for (int i = 0; i < nc; i++) {
            if (!vis[i])
               { ans = dfs(i, adj, vis, -1, pvis);
               if(ans==false)
               return false;}
        }
        return ans;
    }
};