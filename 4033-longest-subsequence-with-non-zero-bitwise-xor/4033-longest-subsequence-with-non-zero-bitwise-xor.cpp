class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n =nums.size();
        int ans=0;
        bool all=true;
        for (int i=0;i<n; i++)
        {
            ans^= nums[i];
            if(nums[i]!=0)
            all=false;
        }
        if(all)
        return 0;

        return (ans==0?n-1:n);
    }
};
