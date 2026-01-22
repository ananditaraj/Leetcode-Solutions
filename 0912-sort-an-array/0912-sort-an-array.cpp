class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        multiset<int> s(nums.begin(),nums.end());
        vector<int> ans(s.begin(), s.end());
        return ans;
        
    }
};