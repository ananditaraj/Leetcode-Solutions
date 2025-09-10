class Solution {
public:
int search(unordered_map<int,int>&mp, int k)
{
    for(auto& [f,s]: mp)
    {
        if(f==k)
        return s;
    }
    return 0;
}
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n = order.size();
        int m = friends.size();
        int a;
        unordered_map<int, int> mp;
        vector<int>ans, anss;

        for(int i =0; i<n; i++)
        mp[order[i]]=i;

        for(int k: friends)
        {
            a =search(mp,k);
            ans.push_back(a);
        }   
        vector<pair<int,int>> tmp; 
        for (int i = 0; i < friends.size(); i++) 
            tmp.push_back({ans[i], friends[i]}); 
        
        sort(tmp.begin(), tmp.end());

        for (auto &p : tmp)
            anss.push_back(p.second);

        return anss;
    }
};