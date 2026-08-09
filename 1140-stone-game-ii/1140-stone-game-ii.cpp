class Solution {
public:
    int dfs(int i,int m, vector<int>&piles, unordered_map<int,int>&mem)
    {
    int n=piles.size(), res=2000000000;
    if(i+m*2>=n) return piles[i];
    int key =(i<<8)|m;
    if(mem.count(key)) return mem[key];

    for(int k=1;k<=m*2; k++)
    res=min(res, dfs(i+k, max(m,k),piles, mem));

    mem[key]=piles[i]-res; return mem[key];
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        for(int i=n-2; i>=0; i--)
        piles[i]+=piles[i+1];
            
        unordered_map<int, int> mem;
        return dfs(0,1,piles,mem);        
    }
};