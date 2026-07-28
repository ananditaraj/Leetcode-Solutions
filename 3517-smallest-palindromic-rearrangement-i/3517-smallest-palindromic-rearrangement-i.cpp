class Solution {
public:
    string smallestPalindrome(string str) {
        vector<int>freq(26,0);

        for (char c:str)
            freq[c-'a']++;

        string f="";char m=0;
        for (int i=0;i<26;i++) {
            f+=string(freq[i]/2,char('a' + i));

            if (freq[i]%2)
                m=char('a'+i);
        }
        string s=f;
        reverse(s.begin(),s.end());

        if (m)
            return f+m+s;
        return f+s;
    }
};