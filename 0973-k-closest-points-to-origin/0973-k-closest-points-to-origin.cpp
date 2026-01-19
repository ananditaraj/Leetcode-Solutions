class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int length= points.size();
        vector<pair<int,int>> check;
        vector<vector<int>>ans;

        for(int i=0; i<length; i++)
        {
            int x=points[i][0];
            int y=points[i][1];

            int distance=x*x + y*y;
            check.push_back({distance,i});
        }
        sort(check.begin(), check.end());
        int j=0;
        for(int j=0; j<k; j++)
        {
            int i=check[j].second;
            ans.push_back({points[i][0], points[i][1]});
        }
        return ans;
        
    }
};