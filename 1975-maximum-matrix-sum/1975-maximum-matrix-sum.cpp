class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(),m=matrix[0].size();
        long long ans=0;vector<int> v;
        int mn=INT_MAX;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mn=min(mn,abs(matrix[i][j]));
                
                if(matrix[i][j]<0)
                    v.push_back(matrix[i][j]);

                ans+=abs((long long)matrix[i][j]);
            }
        }

        if(v.size()%2==0)
            return ans;

        return ans-2LL*mn;
    }
};