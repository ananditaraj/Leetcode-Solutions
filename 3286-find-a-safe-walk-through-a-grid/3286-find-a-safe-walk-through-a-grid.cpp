class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size(), m=grid[0].size();

        int she=health-grid[0][0];
        if (she<=0)
            return false;

        vector<vector<int>>best(n,vector<int>(m,-1));

        queue<tuple<int,int,int>>q;
        q.push({0,0,she});
        best[0][0]=she;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while (!q.empty()) 
        {
            auto [x,y,h]=q.front();
            q.pop();

            if (x==n-1 && y==m-1)
                return true;

            for (int k=0; k<4; k++) 
            {
                int nx=x+dr[k], ny=y+dc[k];

                if (nx<0||nx>=n||ny<0||ny>=m)
                    continue;

                int newh=h-grid[nx][ny];

                if (newh<=0)
                    continue;
                if (newh>best[nx][ny]) 
                {
                    best[nx][ny]=newh;
                    q.push({nx,ny,newh});
                }
            }
        }
        return false;
    }
};