class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>>ans;
        int n=v.size();
        sort(v.begin(),v.end());
        int s=v[0][0], e=v[0][1];
        for(int i=1; i<n; i++)
        {
            if(v[i][0]<=e)
            e=max(e,v[i][1]);

            else 
            {
                ans.push_back({s,e});
                s=v[i][0];
                e=v[i][1];
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};