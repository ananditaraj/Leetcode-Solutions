class Solution {
public:
    int minPartitions(string n) {
        long long i,mx=INT_MIN;
        for(char c:n)
        {
            i= c-'0';
            mx=max(mx,i);
        }
        return mx;        
    }
};