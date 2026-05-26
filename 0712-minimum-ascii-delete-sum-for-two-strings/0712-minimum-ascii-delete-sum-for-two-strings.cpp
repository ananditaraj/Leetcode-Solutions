class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        vector<vector<int>>mat(n+1,vector<int>(m+1,0));
        for(int i=0; i<n;i++)
        {
            for(int j=0; j<m;j++)
            {
                if(s1[i]==s2[j])
                mat[i+1][j+1]=mat[i][j]+s1[i];
                else
                mat[i+1][j+1]=max(mat[i][j+1],mat[i+1][j]);
            }
        }
        int tot=0;
            for(char c:s1) tot+=c;
            for(char c:s2) tot+=c;
            return tot-2*mat[n][m];        
    }
};