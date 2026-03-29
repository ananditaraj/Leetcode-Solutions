#define ll long long
class Solution {
public:
    bool check(vector<vector<int>>&g)
    {
        ll n=g.size(),m=g[0].size();        
        ll tot=0, top=0;
        if(n<2)return false;
        unordered_map<ll, int>bf;
        vector<ll>rs(n,0);
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                bf[g[i][j]]++;
                rs[i]+=g[i][j];
                tot+=g[i][j];
            }
        }
        unordered_map<ll, int>tf;
        for(ll i=1; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                ll v=g[i-1][j];
                tf[v]++;
                if(--bf[v]==0) bf.erase(v);
            }
            top+=rs[i-1];
            ll bot=tot-top;
            if(top==bot)return true;

            ll diff =abs(top-bot);
            if(top>bot)
            {
                if(i==1)
                {if(diff==g[0][0]||diff==g[0][m-1])return true;}
                else if(m==1)
                {if(diff==g[0][0]||diff==g[i-1][0])return true;}
                else if(tf.count(diff)) return true;                       
            }
            else
            {
                ll br=n-i;
                if(br==1)
                {if(diff==g[i][0]||diff==g[i][m-1]) return true;}
                else if(m==1)
                {if(diff==g[i][0]||diff==g[n-1][0])return true;}
                else if(bf.count(diff))return true;
            }
        }
        return false;

    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll n=grid.size(), m=grid[0].size();
        vector<vector<int>> trans(m, vector<int>(n));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                trans[j][i]=grid[i][j];
            }
        }
        return check(grid)||check(trans);
    }
};