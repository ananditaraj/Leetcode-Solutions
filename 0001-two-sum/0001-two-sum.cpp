class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++)
        {
            int y= t-nums[i];
            if(mp.find(y)!=mp.end())
            {
                return {i,mp[y]};
            }
            mp[nums[i]]=i;            
        }
        return {};
        
    }
};