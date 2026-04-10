class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int ans=INT_MAX;

        for (int i=0; i<nums.size();i++) {
            auto&v=mp[nums[i]];
            v.push_back(i);

            if (v.size()>=3)
                ans=min(ans,2*(v.back()-v[v.size()-3]));
        }
        return ans==INT_MAX?-1:ans;
    }
};