class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n=nums.size(), sign,prev=1, ans=0, j=0;

        for(int i=0; i<n; i++)
        {
            if(nums[i]%2==0)
            {
                if(i==(5+6*j))
                {
                    prev=-1*prev;
                sign=prev;
                ans+=(sign*nums[i]);
                j++;
                }
                else
                {
                    sign=prev;
                ans+=(sign*nums[i]);
                }
            }
            else if(nums[i]%2!=0 && i==(5+6*j))
            {
                sign=prev;
                ans+=(sign*nums[i]);
                j++;                
            }
            else
            {
                prev=-1*prev;
                sign=prev;
                ans+=(sign*nums[i]);
            }
        }
        return ans;
    }
};