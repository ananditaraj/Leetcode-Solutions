class Solution {
public:
    int bits(int x)
    {
        int c=0,r;
        while(x>0)
        {
            r=x%2;
            if(r==1)
            c++;
            x=x/2;
        }
        return c;
    }
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>a;

        int i=0;
        while(i<n)
        {
            int j=i;
            while(j+1<n && bits(nums[j])==bits(nums[j+1]))
            {
                j++;
            }
            sort(nums.begin()+i,nums.begin()+j+1);
            i=j+1;
        }
        for(int i=0; i<n-1; i++)
        {
            if(nums[i]>nums[i+1])
            return false;
        }
        return true;
    }
};