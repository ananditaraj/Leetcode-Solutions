class Solution {
public:
    bool dfs(int p, int j, vector<int>& s, map<int,int>& mp, map<pair<int,int>,bool>& dp) {
        if (p == s.back()) 
        return 1;

        if (dp.count({p,j})) 
        return dp[{p,j}];

        for (int k = j-1; k <= j+1; k++) {
            if (k > 0 && mp.count(p+k)) 
            {

                if (dfs(p+k, k, s, mp, dp)) 
                return dp[{p,j}] = 1;
            }
            
        }
        return dp[{p,j}] = 0;
    }

    bool canCross(vector<int>& s) {
        map<int,int> mp;

        for (int x : s) 
        mp[x] = 1;

        map<pair<int,int>,bool> dp;
        return dfs(0, 0, s, mp, dp);
    }
};
