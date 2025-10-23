class Solution {
public:
    int longestBalanced(vector<int>& a) {
         int n=a.size(), ans=0;
        for (int i=0; i<n;i++) 
        {
            unordered_set<int> e, o;
            for (int j=i; j<n;j++) 
            {
                (a[j]%2?o:e).insert(a[j]);
                if (e.size()==o.size()) 
                ans=max(ans, j-i+1);
            }
        }
        return ans;
    }
};