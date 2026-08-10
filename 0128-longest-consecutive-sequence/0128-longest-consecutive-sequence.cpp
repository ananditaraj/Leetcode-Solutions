class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int length=nums.size(), count=1, ans=INT_MIN;
        sort(nums.begin(),nums.end());
        if(length<2)
        return length<1?0:1;
        for(int i=1; i<length; i++)
        {
            if(nums[i]-nums[i-1]==1)
            count++;

            else if(nums[i]!=nums[i-1])
            count=1;

            ans=max(ans,count);
            
        }
        return ans;
    }
};
