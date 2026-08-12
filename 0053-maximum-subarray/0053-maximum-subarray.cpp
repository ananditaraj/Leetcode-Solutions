class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(),r=0, sum=0,ans=INT_MIN;
        if(n<2)
        return nums[0];
        while(r<n)
        {
            sum+=nums[r];
            ans=max(ans,sum);
            if(sum<0)
            sum=0;
                r++;
        }
        return ans;
    }
};