class Solution {
public:
    string inv(string x)
    {
        string a="";
        for(char i:x)
        {
            if(i=='0')
            a+='1';
            else
            a+='0';
        }
        return a;
    }
    string func(int n)
    {
        if(n==1)
        return "0";
        
        string prev=func(n-1);
        string temp= inv(prev);
        reverse(temp.begin(), temp.end());
        return prev+"1"+temp;
    }
    char findKthBit(int n, int k) {
        string s=func(n);
        return s[k-1];        
    }
};