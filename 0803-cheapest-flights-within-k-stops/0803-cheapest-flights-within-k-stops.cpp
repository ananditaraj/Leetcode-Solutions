class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<vector<vector<int>>> adj(n);
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        vector<int> dist(n, 1e9);

        for(int i =0; i<f.size(); i++)
        {
            int u = f[i][0];
            int v = f[i][1];
            int wt = f[i][2];

            adj[u].push_back({v,wt});
        }
        q.push({0,{0,src}});
        dist[src]=0;

        while(!q.empty())
        {
            int stop = q.top().first;
            int d = q.top().second.first;
            int n1= q.top().second.second;

            q.pop();

            if(stop ==(k+1))
            break;

            for(auto it: adj[n1])
            {
                int dis = it[1];
                int nd = it[0];
                
              

                if((dis+d) < dist[nd])
                {
                    dist[nd]=dis+d;
                    q.push({stop+1,{dis+d, nd}});
                    
                }
            }

        }
        if(dist[dst] == 1e9)
            return -1;
        return dist[dst];        
    }
};