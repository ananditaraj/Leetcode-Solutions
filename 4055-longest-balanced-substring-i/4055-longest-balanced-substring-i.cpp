class Solution {
public:
    int longestBalanced(string s) {
        int n =s.size(), ans=0;

        for(int i=0; i<n; i++)
        {
            vector<int>f(26,0);
            for(int j=i; j<n; j++)
            {
                f[s[j]-'a']++;

                
                int mini=INT_MAX,maxi=0;
                for(int k:f)
                {
                    if(k>0)
                    {
                        mini=min(mini,k);
                        maxi=max(maxi,k);
                    }
                }
                if(mini==maxi)
                {
                    ans=max(ans, j-i+1);
                }
            }
        }
        return ans;      

    }
};