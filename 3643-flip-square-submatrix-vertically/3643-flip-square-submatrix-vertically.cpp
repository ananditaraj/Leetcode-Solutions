class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& g, int x, int y, int k) {
        int a=x,b=x+k-1;
        while (a<b) {
            for (int c=y;c<y+k;c++) {
                swap(g[a][c], g[b][c]);
            }
            a++;
            b--;
        }
        return g;
    }
};