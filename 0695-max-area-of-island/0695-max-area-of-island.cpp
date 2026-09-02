class Solution {
public:
    int bfs(vector<vector<int>>&grid, vector<vector<int>>&vis, int i, int j, int n, int m)
    {
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int area=1;
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};

        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int k=0; k<4; k++)
            {
                int nr =r+dr[k];
                int nc =c+dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==-1 && grid[nr][nc]==1)
                {
                    area++;
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), ans=0;
        vector<vector<int>> vis(n, vector<int>(m,-1));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(vis[i][j]==-1 && grid[i][j]==1)
                {
                    ans=max(ans,bfs(grid, vis, i, j, n, m));
                }
            }
        }
        return ans;        
    }
};