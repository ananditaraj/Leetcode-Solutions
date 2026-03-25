#define ll long long
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        ll n=grid.size(), m=grid[0].size();
        vector<vector<int>>ans(n, vector<int>(m));
        //vector<int> s(n*m), p(n*m);
        ll s=1,p=1;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                ans[i][j]=s;
                s=(s*grid[i][j])%12345;
            }            
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ans[i][j]=(p*ans[i][j])%12345;
                p=(p*grid[i][j])%12345;
            }
        }
        return ans;

    }
};