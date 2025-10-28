class Solution {
public:
    int maximalSquare(vector<vector<char>>& a) {
        if(a.empty()||a[0].empty()) 
        return 0;

        int m=a.size(),n=a[0].size(),mx=0;

        vector<vector<int>> d(m+1,vector<int>(n+1));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i-1][j-1]=='1')
                {
                    d[i][j]=1+min({d[i-1][j-1],d[i-1][j],d[i][j-1]});
                    mx=max(mx,d[i][j]);
                }
            }
        }
        return mx*mx;
    }
};