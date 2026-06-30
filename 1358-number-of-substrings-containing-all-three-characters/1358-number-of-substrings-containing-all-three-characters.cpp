class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(), ans=0;
        vector<int>f(3,0);
        int l=0;
        for(int r=0; r<n; r++)
        {
            f[s[r]-'a']++;
            while(f['a'-'a']>0 && f['b'-'a']>0 && f['c'-'a']>0)
            {
                ans+=(n-r);
                //move left
                f[s[l]-'a']--;
                l++;
            }
        }
        return ans;              
        
    }
};