class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<vector<int>> diff(n, vector<int>(m,1e9));
        priority_queue< pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> > q;
    
        q.push({0, {0,0}});
        diff[0][0] = 0;

        int dr[4] ={-1,0,1,0};
        int dc[4] ={0, 1,0,-1};

        while(!q.empty())
        {
            auto it = q.top();
            q.pop();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int k=0; k<4; k++)
            {
                int nr = dr[k]+r;
                int nc = dc[k]+c;

                if((nr>=0 && nr<n && nc>=0 && nc<m))
                {
                    int dif =abs( g[nr][nc] - g[r][c]);
                    if(dif<diff[nr][nc])
                    {
                          diff[nr][nc]=dif;
                        q.push({dif,{nr,nc}});

                    }
                }
            }
        }
        return diff[n-1][m-1];

        
    }
};