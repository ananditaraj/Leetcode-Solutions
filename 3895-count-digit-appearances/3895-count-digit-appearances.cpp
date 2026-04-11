class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans=0,n=nums.size();
        
        for (int i=0;i<n;i++) {
            string s = to_string(nums[i]);
            for (char c:s) {
                if (c==digit+'0')
                    ans++;
            }
        }        
        return ans;
    }
};