class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int>freq;

        for (char c:word)
            freq[c]++;

        vector<int> f;
        for (auto &it:freq)
            f.push_back(it.second);

        sort(f.begin(),f.end(),greater<int>());

        int ans=0;
        for (int i=0;i<f.size();i++) {
            ans+=f[i]*(i/8+1);
        }
        return ans;
    }
};