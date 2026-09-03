class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int>dp(text1.size(),0);
        int ans=0;

        for(char c:text2)
        {
            int curlen=0;
            for(int i=0; i<dp.size(); i++)
            {
                if(curlen<dp[i])
                curlen=dp[i];

                else if(c==text1[i])
                {
                    dp[i]=curlen+1;
                    ans=max(ans,dp[i]);
                }
            }
        }
        return ans;
        
    }
};