class Solution {
public:
    int countCommas(int n) {
        int s=0;
        if(n<=999)
        s+=0;
        else if(n<=100000)
        s+=(n-999)*1;
        return s;
        
        
    }
};