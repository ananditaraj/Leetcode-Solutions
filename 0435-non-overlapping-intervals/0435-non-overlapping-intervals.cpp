class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        int n = in.size(), c=0;
         if(n == 0) return 0;
        sort(in.begin(), in.end(), [](auto &a,auto &b)
        {
            return a[1]<b[1];
        });

        int pv = in[0][1];

        for(int i=0; i<n; i++)
        {
            if(in[i][0]<pv)
            c++;
            else
            pv = in[i][1];
        }
        return c-1;              
    }
};