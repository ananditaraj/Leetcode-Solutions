class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size(), a=floor(n/3);
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int x:nums)
        {
            mp[x]++;
        }
        for(auto &p:mp)
        {
            if(p.second>a)
            ans.push_back(p.first);
        }
        return ans;        
    }
};