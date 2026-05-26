#define ll long long
class Solution {
public:
    int numOfWays(int n) {
        int m=1000000007;
        ll a=6,b=6;

        for (int i=2;i<=n;i++) {
            ll newa=(2*a+2*b)%m;
            ll newb=(2*a+3*b)%m;
            a=newa, b=newb;
        }
                return (a+b)%m;
    }
};