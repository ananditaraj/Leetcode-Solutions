#define ll long long
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto &q:queries)
        {
            int l=q[0], r=q[1], k=q[2], v=q[3];
            int i=l;
            while(i<=r)
            {
                ll temp=nums[i];
                nums[i]=(temp*v)%(1000000007);
                i+=k;
            }
        }
        int ans=0;
        for(int n:nums)
        ans^=n;

        return ans;        
    }
};