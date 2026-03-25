#define ll long long
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll n=grid.size(), m=grid[0].size();
        vector<ll>c,r;
        for(int i=0; i<n; i++)
        {
            ll sc=0;
            for(int j=0; j<m; j++)
            {
                sc+=grid[i][j];
                if(j==(m-1))
                c.push_back(sc);             
            }
        }
        
        for(int j=0; j<m; j++)
        {
            ll sr=0;
            for(int i=0; i<n; i++)
            {
                sr+=grid[i][j];
                if(i==(n-1))
                r.push_back(sr);             
            }
        }
        if(n==1) {
        ll sum=0, p=0;
        for(int j=0; j<m;j++) sum+=grid[0][j];
        for(int j=0; j<m-1;j++) {
            p+=grid[0][j];
            if(p==sum-p) return true;
            }
        return false;
        }

        if(m==1) {
        ll sum=0,p=0;
        for(int i=0; i<n;i++) sum+=grid[i][0];
        for(int i=0;i<n-1; i++) {
            p+=grid[i][0];
            if(p==sum-p) return true;
            }
        return false;
        }
        ll tot=0, p=0;
        for(ll i:c)
        tot+=i;
        for(int i=0; i<n-1; i++)
        {
            p+=c[i];
            if(p==(tot-p))return true;
        }
        ll totr=0, pr=0;
        for(ll i:r)
        totr+=i;
        for(int i=0; i<m-1; i++)
        {
            pr+=r[i];
            if(pr==(totr-pr))return true;
        }
        return false;
    }
};