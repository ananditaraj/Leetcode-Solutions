class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // A A A A A B B B N  N N
        // A -> B, N -> max(n, total no of type - 1) before another A task
        //Soln : 
        // map -> task , freq
        // map traverse -> max freq : count
        // ans = (n + 1) * (max - 1) + c
        int l=tasks.size(), m=INT_MIN;

        vector<int> freq(26,0);
        
        for(int i=0; i<l; i++)
        {
            freq[tasks[i]-'A']++;
        }
        for(int f: freq)
        {
            m=max(m,f);
        }
        
        int c=0;
        for(int f:freq)
        if(f==m)
        c++;
        
        return max(l, (m-1)*(n+1)+c);
        
    }
};