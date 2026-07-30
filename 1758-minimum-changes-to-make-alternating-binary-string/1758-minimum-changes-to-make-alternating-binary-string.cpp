class Solution {
public:
    int minOperations(string s) {
        int n=s.size(),op1=0,op2=0;

        for (int i=0;i<n;i++) {
            char ex1=(i%2==0)?'0':'1';
            if (s[i]!=ex1) op1++;

            char ex2=(i%2==0)?'1':'0';
            if (s[i]!=ex2) op2++;
        }
        return min(op1,op2);
    }
};