class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        vector<vector<int>> ans;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;

            pq.push({dist, i});

            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty()) {
            int i = pq.top().second;
            pq.pop();
            ans.push_back({points[i][0], points[i][1]});
        }

        return ans;
    }
};
