class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size(),c=0;
        for(int i=0; i<n; i++)
        {
            long long e=0,o=0;
            for(int j=i; j<n; j++)
            {
            if(nums[j]%2==0) e++;
            else o++;

            if(o>0 && (e*b<=a*o))
            c++;
            }
        }
        return c;        
    }
};