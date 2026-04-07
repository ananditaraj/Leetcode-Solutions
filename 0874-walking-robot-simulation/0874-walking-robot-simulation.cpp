class Solution {
public:
    int robotSim(vector<int>& comm, vector<vector<int>>& obs) {
        set<pair<int,int>>b;
        vector<pair<int,int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        int x=0,y=0, d=0, md=0;
        for(auto &o:obs)
        b.insert({o[0],o[1]});
        
        for(int c: comm)
        {
            if(c==-1)
            d=(d+1)%4;
            else if(c==-2)
            d=(d+3)%4;
            else{
                while(c--)
                {
                    int nx=x+dir[d].first;
                    int ny=y+dir[d].second;
                    if(b.count({nx,ny})) break;
                    x=nx; y=ny;
                    md=max(md, x*x+y*y);
                }

            }
        }
        return md;
        
    }
};