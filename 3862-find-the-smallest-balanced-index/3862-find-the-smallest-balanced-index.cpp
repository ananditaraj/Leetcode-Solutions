class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        long long s=0, p=1;
        for(int x:nums)
        s+=x;
        for(int i=n-1; i>=0; i--)
        {
            s-=nums[i];
            if(s==p)
            return i;
            if(p>s/nums[i])
            break;
            p*=nums[i];
        }       

        return -1;
    }
};