#define ll long long
class Solution {
public:
    long long countDistinct(long long n) {
        vector<ll>pow(16,1);
        string s=to_string(n);

        ll ans=0,i;

        for(i=1; i<=15; i++)
        {
            pow[i]=pow[i-1]*9;
        }
        for(i=1; i<s.size(); i++)
        ans+=pow[i];

        for(i=0; i<s.size(); i++)
        {
            if(s[i]=='0')
            break;
            for(ll j=1;j<s[i]-'0'; j++)
            ans+=pow[s.size()-1-i];
        }
        return ans+(i>=s.size());
    }
};
