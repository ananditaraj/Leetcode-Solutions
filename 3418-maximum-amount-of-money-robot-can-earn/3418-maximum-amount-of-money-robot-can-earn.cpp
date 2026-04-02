class Solution {
public:
    int dp[501][501][3];
    int solve(vector<vector<int>>& coins, int i ,int j, int k)
    {
        int n=coins.size(), m=coins[0].size();
        if(i>=n||j>=m) return INT_MIN;
        if(dp[i][j][k]!=-1e9) return dp[i][j][k];
        if(i==(n-1)&& j==(m-1))
        {
            if(coins[i][j]<0&& k>0)
            return dp[i][j][k]=0;
            return dp[i][j][k]= coins[i][j];
        }
        
        int r=solve(coins,i,j+1,k),d=solve(coins,i+1,j,k);

        int take=INT_MIN;
        if(r!=INT_MIN) take=max(take,coins[i][j]+r);
        if(d!=INT_MIN) take=max(take, coins[i][j]+d);
        int skip=INT_MIN;
        if(coins[i][j]<0 &&k>0)
        {
            int sd=solve(coins,i+1,j,k-1);
            int sr=solve(coins, i,j+1,k-1);
            skip =max(sd,sr);
        }
        return dp[i][j][k]= max(take,skip);

    }
    int maximumAmount(vector<vector<int>>& coins) {
        //memset(dp,-1,sizeof(dp));
        for(int i=0;i<501;i++)
    for(int j=0;j<501;j++)
        for(int k=0;k<3;k++)
            dp[i][j][k]=-1e9;
        return solve(coins,0,0,2);        
    }
};