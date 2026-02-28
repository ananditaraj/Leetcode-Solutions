class Solution {
public:
    string maximumXor(string s, string t) {
        unordered_map<char,int>f;
        int n=s.size();
        string output="";
        for(char i:t)
        f[i]++;

        for(int i=0; i<n; i++)
        {
            if(s[i]=='1')
            {
                if(f['0']==0)
                {
                    output+='0';
                    f['1']--;
                }
                else
                {
                    output+='1';
                    f['0']--;
                }
            }
            else
            {
                if(f['1']==0)
                {
                    output+='0';
                    f['0']--;
                }
                else
                {
                    output+='1';
                    f['1']--;
                }
            }

        }
        return output;
        
    }
};