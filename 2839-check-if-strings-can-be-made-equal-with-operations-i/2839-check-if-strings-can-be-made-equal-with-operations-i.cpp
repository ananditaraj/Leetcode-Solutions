class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string sc1=s1, sc2=s2;
        sort(sc1.begin(), sc1.end());
        sort(sc2.begin(), sc2.end());
        return (sc1==sc2)&&((s1[0]==s2[2]&&s1[2]==s2[0])||(s1[1]==s2[3]&&s1[3]==s2[1])||(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]==s2[2]&&s1[3]==s2[3]));        
    }
};