class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int res=INT_MAX,i=0;
        unordered_map<int,int>mp;

        for (int& n :nums) {
            int r;
            if (mp.count(n))
                res=min(res,i-mp[n]);

            for (r=0;n;n/=10)
                r =r*10+(n %10);

            mp[r]=i++;
        }

        return res==INT_MAX?-1:res;
    }
};