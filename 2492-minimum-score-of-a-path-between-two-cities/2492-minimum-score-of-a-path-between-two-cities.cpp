class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }

        queue<int> q;
        vector<int> vis(n+1,0);
        q.push(1);
        vis[1]=1;

        int ans=INT_MAX;

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto &[v,w]:adj[u]){
                ans=min(ans,w);
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};