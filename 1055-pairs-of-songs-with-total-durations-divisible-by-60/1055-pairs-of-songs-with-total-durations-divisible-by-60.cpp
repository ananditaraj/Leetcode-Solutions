class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        vector<int> f(60);
        int res=0;
        for(int t:time)
        {
            int r = t%60;
            int c = (60-r)%60;
            res+= f[c];
            f[r]+=1;
        }
        return res;        
    }
};