class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& nn) {
        int n = in.size();
        vector<vector<int>> ans;

        int start= nn[0], end= nn[1];
        bool p=false;

        for (int i= 0; i< n; i++) {
            int s=in[i][0];
            int e= in[i][1];

            if (e<start) 
                ans.push_back({s, e});
            
            else if(s>end) 
            {
                if(!p) 
                {
                    ans.push_back({start,end});
                    p=true;
                }
                ans.push_back({s,e});
            } 
            else 
            {
                start= min(start, s);
                end =max(end, e);
            }
        }
        if(!p) 
        ans.push_back({start, end});

        return ans;
    }
};
