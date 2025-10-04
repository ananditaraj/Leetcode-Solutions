class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int>r;
        if (a.empty()) return r;
    int t=0,b=a.size()-1,l=0,g=a[0].size()-1;
    while(t<=b && l<=g){
        for(int j=l;j<=g;j++) r.push_back(a[t][j]);
        t++;
        for(int i=t;i<=b;i++) r.push_back(a[i][g]);
        g--;
        if(t<=b){
            for(int j=g;j>=l;j--) r.push_back(a[b][j]);
            b--;
        }
        if(l<=g){
            for(int i=b;i>=t;i--) r.push_back(a[i][l]);
            l++;
        }
    }
    return r;
}
};