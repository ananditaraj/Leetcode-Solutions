class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
         vector<int> tc(n+1);
         for(int i=0; i<t.size(); i++)
         {
            tc[t[i][1]]++;
            tc[t[i][0]]--;
         }
         for(int i =1; i<n+1; i++)
         if(tc[i]==n-1) return i;

         return -1;
        
    }
};