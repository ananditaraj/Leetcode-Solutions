class Solution {
public:
    int zeroes(vector<int>& row, int n) {
        int count=0;
        for(int k=n-1; k>=0; k--) {
            if(row[k]==0)
                count++;
            else
                break;
        }
        return count;
    }
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size(), c=0;

        for(int i=0; i<n; i++)
        {
            int req=n-i-1, j=i;
            while(j<n &&zeroes(grid[j],n)<req)
            j++;
            if(j==n)
            return -1;
            while(j>i)
            {
                swap(grid[j],grid[j-1]);
                c++;
                j--;
            }
        }
        return c;
    }
};