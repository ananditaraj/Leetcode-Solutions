class Solution {
public:
    int minInsertions(string s) {
          string t1=s;
        reverse(s.begin(),s.end());
        string t2=s;

       int n=t1.size();
       int m=t2.size();

     vector<int>prev(m+1,0);
     
    for (int i=n-1; i>=0; i--) 
    {
        vector<int>curr(m+1,0);
        for (int j=m-1; j>=0; j--) 
        {
            if (t1[i]==t2[j]) 
                curr[j]=1+prev[j+ 1];
            
            else 
                curr[j]=max(prev[j],curr[j +1]);
        }
        prev=curr;  
    }
     return n-prev[0];
    }
};