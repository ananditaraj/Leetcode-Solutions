class Solution {
public:
void dfs(int u, int n, vector<vector<int>> &adj, vector<int> &vis, vector<vector<int>>&ans) {

        vis.push_back(u);
        if (u == n - 1)  
            ans.push_back(vis);

         else {
            for (int v : adj[u]) 
            {
                dfs(v, n, adj, vis, ans);
            }
        }
        vis.pop_back();
        
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int n = g.size(); 
        vector<vector<int>> adj(n);
        vector<vector<int>>ans;
        vector<int>vis;

        for(int i =0; i<g.size(); i++)
        {
            for(int j =0; j<g[i].size(); j++)
            {
                adj[i].push_back(g[i][j]);
            }
        }
        dfs(0,n,adj,vis, ans);

        return ans;
    }
};