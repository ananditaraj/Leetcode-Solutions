class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n =g.size();
        vector<vector<int>>adj(g.size());
        vector<int>outdegree(n);
        queue<int>q;
        vector<int>topo;

        for(int i =0; i<n; i++)
        {
            for(int j =0; j<g[i].size(); j++)
            {
                adj[g[i][j]].push_back(i);
                outdegree[i]++;
            }  
        }
         

        for(int i =0; i<outdegree.size(); i++)
        {
            if(outdegree[i]==0)
            q.push(i);
        }

        while(!q.empty())
        {
            int val = q.front();
            q.pop();
            topo.push_back(val);

            for(auto it: adj[val])
            {
                  outdegree[it]--;  
                if(outdegree[it]==0)
                q.push(it);
            }
                    
        }
        sort(topo.begin(), topo.end());
        return topo;
    }
};