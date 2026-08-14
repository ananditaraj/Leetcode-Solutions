class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size(), l=0,ans=-1;
        unordered_map<char,int>map;

        for(int r=0;r<n; r++)
        {
            map[s[r]]++;

            while(map[s[r]]>2)
            {
                map[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;        
    }
};