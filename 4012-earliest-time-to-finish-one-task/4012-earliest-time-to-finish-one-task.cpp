class Solution {
public:
    int earliestTime(vector<vector<int>>& t) {
        int ans=INT_MAX, diff=0;
        for(int i =0; i<t.size(); i++)
        {
            int s = t[i][0];
            int e = t[i][1];
            diff = s+e;
            ans = min(ans, diff);
        }
        return ans;        
    }
};