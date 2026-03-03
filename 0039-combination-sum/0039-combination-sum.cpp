class Solution {
public:
vector<vector<int>> a;

    void f(vector<int>& c, int t, int i, vector<int>& v) 
    {
        if(t==0) {
            a.push_back(v);
            return;
        }

        for(int j=i; j<c.size(); j++) {
            if(c[j]>t) continue;

            v.push_back(c[j]);
            f(c,t-c[j],j,v);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& c, int t) {
            vector<int> v;
        f(c, t, 0, v);
        return a;
    }
};