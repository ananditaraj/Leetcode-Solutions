class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size(), c0=colors[0], cN=colors[n-1];
        int lMax=0, rMax=0;
        for(int i=0; i<n; i++){
            int c=colors[i];
           if (c0!=c && i>lMax)lMax=i;
           if (cN!=c && i>rMax) rMax=n-1-i;
        }
        return max(lMax, rMax);
    }
};