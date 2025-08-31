class Solution {
public:
    bool stoneGame(vector<int>& p) {
        int n = p.size(), maxi, mini, a=0,b=0;

        for(int i =0; i<n; i++)
        {
            maxi = max(p[i],p[n-i-1]);
            mini = min(p[i],p[n-i-1]);
            a+=maxi;
            b+=mini;

           int l  = i;
           int r = n - i - 1;

           if (l<r) {
           p.erase(p.begin() + r); 
           p.erase(p.begin() + l); 
           } 
           else if (l > r) {
            p.erase(p.begin() + l);
            p.erase(p.begin() + r);
           } 
           else { 
    
            p.erase(p.begin() + l);
           }

        }
        return (a>b)? true:false;
        
    }
};