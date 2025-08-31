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

           int left  = i;
           int right = n - i - 1;

           if (left < right) {
           p.erase(p.begin() + right); 
           p.erase(p.begin() + left); 
           } 
           else if (left > right) {
            p.erase(p.begin() + left);
            p.erase(p.begin() + right);
           } 
           else { 
    
            p.erase(p.begin() + left);
           }

        }
        return (a>b)? true:false;
        
    }
};