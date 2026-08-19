class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(), low=0, high=n-1, mid=0;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                mid++;
                low++;//1
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;//4 //3
            }
        }
        for(int i=0; i<n; i++)
        cout<<nums[i]<<" ";
    }
};