class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<int>> mat(m, vector<int>(n,-1));
        int count=0;

        for(auto it: g)
        {
            int r = it[0];
            int c = it[1];
            mat[r][c]=1;           
        }
        for(auto it: w)
        {
            int r = it[0];
            int c = it[1];
            mat[r][c]=2;     
        }
        for(int i =0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]==1)
                {
                    for(int k=i+1;k<m;k++)
                    {  
                         if(mat[k][j]==2 || mat[k][j]==1)
                        break;
                        if(mat[k][j]==-1)                      
                        mat[k][j]=0;

                       
                    }
                    for(int k=i-1;k>=0; k--)
                    {  
                        if(mat[k][j]==2 || mat[k][j]==1)
                        break;
                        if(mat[k][j]==-1)                      
                        mat[k][j]=0;

                        
                    }
                    for(int l=j+1;l<n; l++)
                    {  
                          if(mat[i][l]==2 || mat[i][l]==1)
                        break;
                        if(mat[i][l]==-1)                      
                        mat[i][l]=0;
                      
                    }
                    for(int l=j-1;l>=0; l--)
                    {  
                        if(mat[i][l]==2 || mat[i][l]==1)
                        break;
                        if(mat[i][l]==-1)                      
                        mat[i][l]=0;
                        
                    }
                }
            }
        
        }
        for(int i =0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]==-1)
                count++;
            }
        }
        return count;

    }
};