class Solution {
public:
    int mirrorDistance(int n) {
        int x=n,a=0;
        while(x!=0)
        {
            a= a*10+(x%10); 
            x/=10;
        }
        return abs(n-a);        
    }
};