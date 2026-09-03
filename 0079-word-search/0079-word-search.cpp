class Solution {
public:
bool dfs(vector<vector<char>>&b,vector<vector<bool>>&vis,int i,int j, int n,int m,string w, int x)
{
    if(b[i][j]!=w[x])
    return false;
    if(x==w.size()-1)
    return true; 

    vis[i][j]=true;

    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};

    for(int k=0; k<4; k++)
    {
        int nr=i+dr[k];
        int nc=j+dc[k];
        if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]&& b[nr][nc]==w[x+1])
        {
            if(dfs(b,vis,nr,nc,n,m,w,x+1))
            return true;
        }
    }   
    vis[i][j]=false;
    return false;
}
    bool exist(vector<vector<char>>& b, string w) {
        int n=b.size(), m=b[0].size(); bool ans=false;
        vector<vector<bool>>vis(n, vector<bool>(m,false));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(b[i][j]==w[0])
                {
                    if(dfs(b,vis,i,j,n,m,w,0))
                    return true;
                }
            }
        }
        return ans;
    }
};