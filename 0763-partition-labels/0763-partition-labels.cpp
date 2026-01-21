class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int> ans;
        vector<pair<int,int>> v;

        for(int i=0; i<n; i++)
        {
            int posj=0, posi=INT_MAX;
            for(int j=0;j<n; j++)
            {
                if(s[i]==s[j])
                {
                    posi=min(i,posi);
                    posj=max(posj,j);                
                }
            }
            v.push_back({posi,posj});
        }

        sort(v.begin(), v.end());
    int st=v[0].first;
    int e=v[0].second;

    for (int i=1;i<v.size(); i++) {

        if (v[i].first<=e)
            e=max(e,v[i].second);

        else {
            ans.push_back(e-st+1);
            st=v[i].first;
            e=v[i].second;
        }
    }
    ans.push_back(e-st+1);

    return ans;
}
};