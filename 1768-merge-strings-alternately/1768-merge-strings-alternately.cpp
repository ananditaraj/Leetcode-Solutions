class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int j=-1;

        for(int i=0; i<word1.size(); i++)
        {
            ans+=word1[i];
            j++;
            if(j<word2.size())       
            ans+=word2[j];   
        }
        if(j<word2.size())
        ans+= word2.substr(j+1,word2.size()-j-1);
        
        return ans;
    }
};