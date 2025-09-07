class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int> ans;

        for(int i: nums)
        mp[i]++;

        priority_queue<pair<int,int>>q;
        for(auto& i:mp)
        q.push({i.second, i.first});

        while(!q.empty() && k>0)
        {
            ans.push_back(q.top().second);
            q.pop();
            k--;
        }
        return ans;
        
    }
};