class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int v=*min_element(nums.begin(), nums.end());
        for(int x:nums)
        {
            if(x%v>0)
            return 1;
        }
        int c=count(nums.begin(), nums.end(),v);
        return (c+1)/2;
        
    }
};