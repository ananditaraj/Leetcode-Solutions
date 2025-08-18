class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>> dist(n, vector<int>(n,INT_MAX));
        priority_queue< pair<int, pair<int,int>>, 
                vector<pair<int, pair<int,int>>>, 
                greater<pair<int, pair<int,int>>> > q;

        
        if(g[0][0]!=0)
        return -1;
        
        q.push({0, {0,0}});
        dist[0][0]=0;
        
        while(!q.empty())
        {
            auto it = q.top();
            q.pop();

            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;

            int dr[8] ={-1,-1,0,1,1,1,0,-1};
            int dc[8] ={0,1,1,1,0,-1,-1,-1};

            for(int k=0; k<8; k++)
            {
                int nr = r+dr[k];
                int nc = c+dc[k];

                if((nr>=0 && nr< n && nc>=0 && nc<n) && g[nr][nc]==0)
                {

                    
                   
                    if(dist[nr][nc] > d+1)
                    {
                        dist[nr][nc]=d+1;
                         q.push({d+1, {nr,nc}});
                    }
                }
            }

        }
        if(dist[n-1][n-1]==INT_MAX)
        return -1;
        return dist[n-1][n-1]+1;


    }
};