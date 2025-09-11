class Solution {
public:
    int minOperations(string s) {
        priority_queue<char, vector<char>, greater<char>> q;

        for(char c: s)
            q.push(c);
        
        while (!q.empty() && q.top() == 'a')
            q.pop();

        if(q.size()==0)
        return 0;
        else
        return 'z'-q.top()+1;        
    }
};