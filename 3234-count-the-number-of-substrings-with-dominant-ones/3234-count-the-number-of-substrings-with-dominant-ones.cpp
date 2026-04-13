class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(); vector<int>z;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='0') z.push_back(i);
        }
        int o=n-z.size(), res=0,sid=0;
        z.push_back(n);
        for(int l=0; l<n; l++)
        {
            for(int i=sid; i<z.size()-1;i++)
            {
                int c=i-sid+1;
                if(c*c>o) break;
                int p=z[i], q=z[i+1], c1=z[i]-l-(i-sid);
                if(c1>=c*c)
                res+=q-p;
                else
                res+=max(q-p-(c*c-c1),0);
            }
            if(s[l]=='0')sid++;
            else
            {
                res+=z[sid]-l; o--;
            }
        }
        return res;
    }
};