class Solution {
public:
    long long fact(long long n)
    {
        if(n==0 || n==1)
        return 1;
        else
        return fact(n-1)*n;
    }
    bool isDigitorialPermutation(long long n) {
        long long d,ans=0, a=n;
        while(n>0)
        {
            d=n%10;
            ans+= fact(d);
            n/=10;
        }
        string s1= to_string(ans);
        string s2= to_string(a);
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return (s1==s2);
        
    }
};