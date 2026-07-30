class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        if(n<9)
        return n;
        else if(n>=9 && n<17)
        {
            int rem =n-8;
            return 8+rem*2;
        }
        else if( n>=17&& n<25)
        {
            int rem2=n-16;
            return 8+8*2+rem2*3;
        }
        else
        return 8+16+8*3+(n-24)*4;        
    }
};