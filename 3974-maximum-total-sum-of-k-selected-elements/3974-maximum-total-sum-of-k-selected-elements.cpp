class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long n=nums.size(), sum=0;
        sort(nums.rbegin(), nums.rend());
        for(int i=0; i<k; i++)
        {
            if(mul>0)
            sum+=1LL*nums[i]*mul;
            if(mul<=0)
            sum+=nums[i];
            mul--;
        }
        return sum;       
    }
};