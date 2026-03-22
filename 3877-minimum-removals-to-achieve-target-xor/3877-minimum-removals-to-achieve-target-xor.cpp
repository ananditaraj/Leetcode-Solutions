#define ll long long
class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n=nums.size(), MAX=1e5;
        vector<int> dp(MAX+1,-1);
        dp[0]=0;
        for(int x:nums)
        {
            vector<int>ndp=dp;
            for(int i=0; i<=MAX; i++)
            {
                if(dp[i]!=-1)
                ndp[i^x]=max(ndp[i^x],dp[i]+1);
            }
            dp=ndp;
        }
        if(dp[target]==-1)return -1;
        return n-dp[target];
        
    }
};