#define ll long long
class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, vector<int>>pos;
        vector<int> idx[30][2];
        for(int i=0; i<n; i++)
        {
            pos[nums[i]].push_back(i);
            for(int b=0; b<30; b++)
            idx[b][(nums[i]>>b)&1].push_back(i);
        }
        ll ans=0;
        for(int i=0; i<n; i++)
        {
            int l=0,r=n-1;
            for(int b=0; b<30; b++)
            {
                if(((nums[i]>>b)&1)==0)
                {
                    auto ir=lower_bound(idx[b][1].begin(), idx[b][1].end(),i);
                    if(ir!=idx[b][1].end())
                    r=min(r,*ir-1);

                    auto il=lower_bound(idx[b][1].begin(), idx[b][1].end(),i);
                    if(!idx[b][1].empty() &&il!=idx[b][1].begin())
                    {
                        il--;//new
                       l=max(l,*il+1);
                    }

                }
            }
            auto &v=pos[nums[i]];
            auto it=upper_bound(v.begin(),v.end(),i);
            if(it!=v.end()) r=min(r,*it-1);
            ans+=1LL*(i-l+1)*(r+1-i);

        }
        return ans;
    }
};