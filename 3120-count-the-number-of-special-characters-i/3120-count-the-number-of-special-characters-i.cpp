class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size(),cnt=0;

        for(char ch='A';ch<='Z';ch++)
        {
            if(word.find(ch)!=string::npos && word.find(tolower(ch))!=string::npos)
            cnt++;
        }

        return cnt;
    }
};