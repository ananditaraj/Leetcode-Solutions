class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size(), m=word2.size(),c=0, x=m-1;
        vector<int> v(n), ans;
        for(int i=n-1; i>=0; i--)
        {
            v[i]=c;
            if(x>=0 && word1[i]==word2[x])
            {
                x--;c++;
            }
        }
        bool ch=false; int j=0;
        for(int i=0; i<n&&j<m; i++)
        {
            if(word1[i]==word2[j])
            {
                ans.push_back(i);
                j++;
            }
            else if(!ch&&v[i]>=m-1-j)
            {
                ans.push_back(i); j++;
                ch=true;
            }
        }
        return j==m?ans:vector<int>{};
        
    }
};