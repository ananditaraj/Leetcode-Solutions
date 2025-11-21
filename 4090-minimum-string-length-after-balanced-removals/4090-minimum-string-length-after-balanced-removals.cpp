class Solution {
public:
    int minLengthAfterRemovals(string s) {
        unordered_map<char,int>f;
        for(char c:s)
        {
            f[c]++;
        }
        int a=f['a'];
        int b=f['b'];
        return s.length()-2*min(a,b);        
    }
};