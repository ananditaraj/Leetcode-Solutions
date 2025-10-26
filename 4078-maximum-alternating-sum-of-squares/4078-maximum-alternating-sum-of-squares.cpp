class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long ans=0;

        for(int i =0; i<n; i++)
         nums[i]=abs(nums[i]);               
        
        sort(nums.begin(), nums.end());

        for (int i=0; i<n/2; i++) 
        {
        long long big =1LL*nums[n-i-1]*nums[n-i-1];
        long long small =1LL*nums[i]*nums[i];
        ans+=big-small;
        }
        
        if (n%2==1)
        ans+=1LL*nums[n/2]*nums[n/2];

    return ans;
    }
};