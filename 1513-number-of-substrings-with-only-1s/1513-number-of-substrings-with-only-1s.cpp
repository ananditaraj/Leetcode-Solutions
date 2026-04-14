class Solution {
public:
    int mod=1e9+7;
    int numSub(string s) {
        int c=0, tot=0;
        for(char ch:s)
        {
            if(ch=='1') c++;
            else c=0;
            tot=(tot+c)%mod;
        }
        return tot;

        
        
    }
};