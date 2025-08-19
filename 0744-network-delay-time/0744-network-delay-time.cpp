class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        vector<vector<vector<int>>>adj(n+1);
        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;

        for(int i =0; i<t.size(); i++)
        {
            int u = t[i][0];
            int v = t[i][1];
            int wt = t[i][2];

            adj[u].push_back({v,wt});
        }
        q.push({0,k});
        dist[k] =0;

        while(!q.empty())
        {
            int di = q.top().first;
            int node = q.top().second;

            q.pop();

            for(auto it: adj[node])
            {
                int wt = it[1];
                int n = it[0];

                if((di+wt) < dist[n])
                {
                    dist[n] = di+wt;
                    q.push({di+wt, n});
                }
            }
        }  
        int maxi=0;  
        for(int i =1; i<dist.size(); i++)
        {
            if(dist[i] == 1e9)
            return -1;
            else
            {
                if(dist[i] > maxi)
                maxi = dist[i];
            }
        }    
        return maxi;
    }
};