class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n=capacity.size(), m=INT_MAX;
        for(int i=0;i<n; i++)
        {
            if(capacity[i]>=itemSize)
            m=min(m,capacity[i]);
        }
        for(int i=0;i<n; i++)
        {
            if(m==capacity[i])
            return i;
        }
        return -1;
        
    }
};