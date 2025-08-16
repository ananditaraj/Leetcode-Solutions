class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& b) {
        int n = b.size();
        int m = b[0].size();

        vis[i][j] = 1;
        b[i][j] = '*';

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if ((nr >= 0 && nc >= 0 && nr < n && nc < m) && b[nr][nc] == 'O' &&!vis[nr][nc]) {
                dfs(nr, nc, vis, b);
            }
        }
    }
    void solve(vector<vector<char>>& b) {
        int n = b.size();
        int m = b[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && b[i][j] == 'O') {
                    dfs(i, j, vis, b);
                }
            }
        }

        for(int i =0; i<n; i++)
        {
            for(int j=0; j<m;j++)
            {
                if(b[i][j]=='*')
                b[i][j]='O';
                else
                if(b[i][j]=='O')
                b[i][j]='X';
            }
        }
    }
};