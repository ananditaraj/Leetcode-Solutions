class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int> s(nums.begin(), nums.end());
        vector<int> v(s.begin(), s.end());
        vector<int> ans;
        
        int n=v.size();
        for(int i=n-1;i>=0&&k>0;i--,k--) ans.push_back(v[i]);
        return ans;
    }
};
