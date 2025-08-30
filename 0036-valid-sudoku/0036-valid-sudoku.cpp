class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        
        for(int i = 0; i < 9; i++) 
        {
            vector<int> row(10,0), col(10,0);
            
            for(int j = 0; j < 9; j++) 
            {
                if(b[i][j] != '.') 
                {
                    int d = b[i][j]-'0';
                    if(row[d]++) 
                    return false;
                }
                if(b[j][i] != '.') 
                {
                    int d = b[j][i]-'0';
                    if(col[d]++) return false;
                }
            }
        }

        for(int bi = 0; bi < 9; bi += 3) 
        {
            for(int bj = 0; bj < 9; bj += 3) 
            {
                vector<int> box(10,0);

                for(int i = 0; i < 3; i++) 
                {
                    for(int j = 0; j < 3; j++) 
                    {
                        char c = b[bi+i][bj+j];
                        if(c != '.') {
                            int d = c - '0';
                            if(box[d]++) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
