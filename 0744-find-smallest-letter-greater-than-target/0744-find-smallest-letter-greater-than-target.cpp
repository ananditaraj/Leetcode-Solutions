class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans='{';

        for(char &s:letters)
        {
            if(s>target)
            {
                ans=min(ans,s);
            }
        }        
        return ans=='{'?letters[0]:ans;
        
    }
};