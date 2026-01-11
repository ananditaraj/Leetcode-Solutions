class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        int n =strs.size();
        unordered_map<string, vector<string>>mp;

        for(int i=0; i<n; i++)
        {
            string s2=strs[i];
            sort(s2.begin(), s2.end());
            mp[s2].push_back(strs[i]);
        }
        for(auto&i:mp)
        {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};