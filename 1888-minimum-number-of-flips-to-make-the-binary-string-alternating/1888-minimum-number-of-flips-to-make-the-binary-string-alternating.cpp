class Solution {
public:
    int minFlips(string s) {
        int n=s.size(), c=0;
        string a="",b="", t=s+s;
        for(int i=0; i<2*n; i++)
        {
            a+=(i%2?'1':'0');
            b+=(i%2?'0':'1');
        }
        int x=0, y=0, ans=n;
        for(int i=0; i<2*n; i++)
        {
            if(t[i]!=a[i])x++;
            if(t[i]!=b[i])y++;

            if(i>=n)
            {
                if(t[i-n]!=a[i-n]) x--;
                if(t[i-n]!=b[i-n])y--;
            }
            if(i>=n-1)
            ans=min(ans, min(x,y));
        }
        
        return ans;
        
    }
};