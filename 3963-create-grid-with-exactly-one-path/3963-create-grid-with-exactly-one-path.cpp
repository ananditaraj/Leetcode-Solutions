class Solution {
public:
    vector<string> createGrid(int m, int n) 
    {
        vector<string>ans;
        string temp(n,'.');
        ans.push_back(temp);
        for(int i=1;i<m;i++)
        {
            string t(n-1,'#');
            t+='.';
            ans.push_back(t);
        }
        return ans; 
    }
};