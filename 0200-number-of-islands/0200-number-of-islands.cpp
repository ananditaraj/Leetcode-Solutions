class Solution {
    private:
    void dfs(int i,int j, vector<vector<int>>&vis, vector<vector<char>>&g)
    {
        int n=g.size();
        int m =g[0].size();
        vis[i][j]=1;

        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};

        for(int k=0; k<4; k++)
        {
            int nr = i+dr[k];
            int nc = j+dc[k];

            if((nr>=0 && nr<n && nc>=0 && nc<m) && vis[nr][nc]==0 && g[nr][nc]=='1')
            {
                dfs(nr,nc,vis,g);
            }

        }
    }
public:
    int numIslands(vector<vector<char>>& g) {
        int c=0;
        int n=g.size();
        int m =g[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));

        for(int i =0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                if(g[i][j]=='1' && vis[i][j]==0)
                {
                    c++;
                    dfs(i,j,vis,g);
                }
            }
        }
        return c;
    }
};