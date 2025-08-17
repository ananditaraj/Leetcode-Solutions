class Solution {
public:
    vector<int> findOrder(int nc, vector<vector<int>>& p) {
        vector<vector<int>> adj(nc);
        vector<int>indegree(nc,0);
        vector<int>topo;
        queue<int>q;

        for(int i =0; i<p.size(); i++)
        {
            int u =p[i][0];
            int v =p[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }
        for(int i=0; i<indegree.size(); i++)
        {
        if(indegree[i]==0)
        q.push(i);
        
        }

        while(!q.empty())
        {
            int val = q.front();
            q.pop();
            topo.push_back(val);

            for(auto it: adj[val])
            {
                indegree[it]--;

                if(indegree[it]==0)
                q.push(it);
            }
        }
        reverse(topo.begin(), topo.end());
        return (topo.size()==nc? topo:vector<int>{});        
    }
};