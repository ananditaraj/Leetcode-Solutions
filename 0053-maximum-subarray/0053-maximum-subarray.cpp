class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int l =0, r=0;
        int ans =INT_MIN, sum=0;

        if(n<2)
        return nums[0];

        while(r<n)
        {
            sum += nums[r];
            ans = max(ans, sum);

            if(sum<0)
            sum =0;
            r++;
        }
        return ans;
    }
};