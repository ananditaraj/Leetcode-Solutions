class Solution {
public:
    vector<int>dr={0,0,-1,1};
    vector<int>dc={-1,1,0,0};

    void calc(vector<vector<int>>& g,vector<vector<int>>& d, int n) {
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(g[i][j]) 
                {
                    d[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()) 
        {
            auto [x,y]=q.front();
            q.pop();

            for(int k=0;k<4;k++) {
                int nx=x+dr[k];
                int ny=y+dc[k];

                if(nx>=0&&nx<n&& ny>=0&&ny<n&& d[nx][ny]>d[x][y]+1) 
                {
                    d[nx][ny]=d[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& g) {
        int n=g.size();

        if(g[0][0]||g[n-1][n-1])
            return 0;

        vector<vector<int>>d(n, vector<int>(n, INT_MAX));
        calc(g,d,n);

        vector<vector<bool>> vis(n,vector<bool>(n,false));

        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({d[0][0],{0,0}});

        while(!pq.empty()) 
        {
            auto cur=pq.top();
            pq.pop();

            int sf=cur.first,x =cur.second.first, y=cur.second.second;

            if(x==n-1 && y==n-1)
                return sf;

            if(vis[x][y])
                continue;

            vis[x][y]=true;

            for(int k=0;k<4; k++) {
                int nx=x+dr[k];
                int ny=y+dc[k];

                if(nx>=0 &&nx<n&& ny>=0 && ny<n &&!vis[nx][ny])
                    pq.push({min(sf, d[nx][ny]), {nx, ny}});
            }
        }

        return -1;
    }
};