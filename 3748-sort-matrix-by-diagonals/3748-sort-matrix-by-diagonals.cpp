class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& g) {
        int n = g.size();

        for (int j = 0; j < n; j++) {
            vector<int> v;

            for (int r = 0, c = j; r < n && c < n; r++, c++) 
            v.push_back(g[r][c]);

            if (j == 0) 
            sort(v.begin(), v.end(), greater<int>());
            else 
            sort(v.begin(), v.end());

            for (int r = 0, c = j, k = 0; r < n && c < n; r++, c++, k++) 
            g[r][c] = v[k];
        }

        for (int i = 1; i < n; i++) {
            vector<int> v;
            for (int r = i, c = 0; r < n && c < n; r++, c++) 
            v.push_back(g[r][c]);
            
            sort(v.begin(), v.end(), greater<int>());
            for (int r = i, c = 0, k = 0; r < n && c < n; r++, c++, k++) 
            
            g[r][c] = v[k];
        }

        return g;
    }
};
