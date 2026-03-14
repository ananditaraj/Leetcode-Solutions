class Solution {
public:
    string getHappyString(int n, int k) {
        int sz=pow(2,n-1);
        if(3*sz <k) 
        return "";
        string ans="";
        if(k<=sz)
        ans+='a';
        else if(k<=2*sz)
        {
            ans+='b';
            k-=sz;
        }
        else
        {
            ans+='c';
            k-=2*sz;
        }
        string opts[]={"bc", "ac", "ab"};
            
        for(int i=1; i<n; i++)
        {
            sz/=2;
            string ch=opts[ans.back()-'a'];
            if(k<=sz)
            ans+=ch[0];
            else
            {
                ans+=ch[1];
                k-=sz;
            }
        }
        return ans;
        
    }
};