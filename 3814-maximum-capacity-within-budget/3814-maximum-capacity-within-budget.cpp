class Solution {
public:
    int maxCapacity(vector<int>& c, vector<int>& p, int b) {
        int n = c.size(), ans = 0;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({c[i], p[i]});
        sort(v.begin(), v.end());
        vector<int> pre(n);
        pre[0] = v[0].second;
        for (int i = 1; i < n; i++)
            pre[i] = max(pre[i - 1], v[i].second);
        for (int i = 0; i < n; i++) {
            if (v[i].first < b)
                ans = max(ans, v[i].second);
            int rem = b - v[i].first - 1;
            int l = 0, r = i - 1, idx = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (v[m].first <= rem)
                    idx = m, l = m + 1;
                else
                    r = m - 1;
            }
            if (idx != -1)
                ans = max(ans, v[i].second + pre[idx]);
        }
        return ans;
    }
};
