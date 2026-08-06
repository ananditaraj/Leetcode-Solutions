class Solution {
public:
    int digit(int x)
    { int p=1,d;
        while(x>0)
        {
            d=x%10;
            p*=d;
            x/=10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        while(true)
        {
            if(digit(n)%t==0)
            return n;
            else
            n++;
        }
        return 0;        
    }
};