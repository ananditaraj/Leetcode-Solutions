class Solution {
public:
    int numSpecial(vector<vector<int>>& a){
int m=a.size(),n=a[0].size(),c=0;
vector<int> r(m),d(n);

for(int i=0;i<m;i++)
for(int j=0;j<n;j++)
if(a[i][j]){r[i]++;d[j]++;}

for(int i=0;i<m;i++)
for(int j=0;j<n;j++)
if(a[i][j]&&r[i]==1&&d[j]==1)c++;

return c;
}
};