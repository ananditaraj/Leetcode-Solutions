#define ll long long
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        ll n=s1.size(), ans=0;
        string sc1=s1, sc2=s2;
        sort(sc1.begin(), sc1.end());
        sort(sc2.begin(), sc2.end());
        if(sc1!=sc2)
        return false;
        vector<int>e(26,0);
        vector<int>o(26,0);

        for(int i=0; i<n; i++)
        {
            if(i%2==0)
            {
                e[s1[i]-'a']++;
                e[s2[i]-'a']--;
            }
            else
            {
                o[s1[i]-'a']++;
                o[s1[i]-'a']--;
            }            
        }
        for(int i=0; i<26; i++)
        {
            if(e[i]!=0||o[i]!=0)
            return false;
        }
        return true;        
    }
};