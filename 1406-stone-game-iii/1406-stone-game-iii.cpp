class Solution {
public:
    string stoneGameIII(vector<int>& sv) {
        int n=sv.size();
        vector<int> dp(n+1, 0);

        for (int i=n-1; i>=0; i--) {
            int ans=INT_MIN,s=0;
            for (int k=1;k<=3;k++) 
            {
                if (i+k>n) break;
                s+=sv[i+k-1];
                ans=max(ans, s-dp[i+k]);
            }
            dp[i]=ans;
        }
        return dp[0]>0?"Alice":(dp[0]<0?"Bob":"Tie");
    }
};