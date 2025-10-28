class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.size();
        int sh=0;
        for (int i=n-1;i>=0;i--) 
        {
            sh=(sh+shifts[i])%26;
            s[i]=(char)((s[i]-'a'+sh)%26+'a');
        }
        return s;
        
    }
};