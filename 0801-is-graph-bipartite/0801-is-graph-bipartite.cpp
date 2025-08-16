class Solution {
public:
bool dfs(int node, vector<vector<int>>&g, vector<int>&vis, vector<char>&c)
{
    bool ans =true;
    vis[node]=1;

    for(auto it: g[node])
    {
        if(!vis[it])
        {
            if(c[node]=='P')
            c[it]='Q';
            else
            c[it]='P';

            ans &= dfs(it,g,vis,c);
        }
        else if( vis[it] && c[node] == c[it])
        return false;
    }
    return ans;
    
}
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        vector<char> c(n, '*');
        vector<int> vis(n,0);
        bool ans =true;

        for(int i =0; i<n;i++)
        {
            if(!vis[i])
            {
                c[i] = 'P';
                ans &= dfs(i, g, vis, c);
            }
        }  
        return ans;      
    }
};