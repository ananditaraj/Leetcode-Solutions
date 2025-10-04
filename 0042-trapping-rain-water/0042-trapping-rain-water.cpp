class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();

        int l =0, r = n-1, lm= h[0], rm=h[n-1], ans=0;
        while(l<=r)
        {
            if(h[l]<=h[r])
            {
                lm =max(lm,h[l]);
                ans+= (lm -h[l]);
                l++;  
            }
            else
            {
                rm = max(rm,h[r]);
                ans+=(rm-h[r]);
                r--;
            }
        }
        return ans;
        
    }
};