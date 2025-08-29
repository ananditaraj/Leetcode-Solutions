class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.size(), ans = 0;

        vector<int> v(n,0);
        vector<int>c(n,0);
        
        for(int i =0;i<n; i++)
        {
            if(s[i]=='a'|| s[i]=='e'|| s[i]=='i'||s[i]=='o'||s[i]=='u')
            v[i] = 1;
            else
            c[i] =1;
        }
        for(int i=1;i<n;i++)
        {
            v[i]+=v[i-1];
            c[i]+=c[i-1];
        }

        for(int i=0; i<n; i++)
        {
            for(int j =i+1; j<n; j++)
            {
                int vv= v[j];
            int cc= c[j];
                if(i!=0)
                {
                    vv-=v[i-1];
                    cc-=c[i-1];
                    
                }
                if(vv==cc && (vv*cc)%k==0)
                ans++;
            }
        }
        return ans;       
    }
};
