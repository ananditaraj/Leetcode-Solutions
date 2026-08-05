class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node]=true;
        for (int next:adj[node]) {
            if (!vis[next])
            dfs(next, adj, vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<bool> vis(n,false);
        for (auto e:invocations) {
            adj[e[0]].push_back(e[1]);
        }
        dfs(k, adj, vis);

        for (auto e:invocations) {
            int u=e[0],v=e[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i=0;i<n;i++)
                ans.push_back(i);
                return ans;
            }
        }
        vector<int> ans;
        for (int i=0;i<n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};