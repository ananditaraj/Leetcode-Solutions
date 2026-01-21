class Solution {
public:
    string predictPartyVictory(string s) {
        int n=s.size();
        queue<int> r,d;
        
        for(int i=0; i<n; i++)
        {
            if(s[i]=='R')
            r.push(i);
            else d.push(i);
        }
        while(!r.empty() && !d.empty())
        {
            int r1=r.front(); r.pop();
            int d1=d.front(); d.pop();

            if(r1<d1)
            r.push(r1+n);
            else 
            d.push(d1+n);
        }
        return r.empty()?"Dire" : "Radiant";

    }
};