class Solution {
public:
    int ladderLength(string b, string e, vector<string>& w) {
        int n = w.size(), c=0;
        map< string, set<string>> adj;

        priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> q;
        map<string, int>dist;
bool ans=false;
        for(int i =0; i<n;i++)
        {
            if(w[i]==e)
            {
                ans=true;
            }
            dist[w[i]]=1e9;
        }
        for(int i=0;i<n;i++)
        {
            c=0;
            for(int j=0;j<b.length();j++)
            {
                if(b[j]!=w[i][j])
                c++;
            }
            if(c==1)
            {
                adj[b].insert(w[i]);
                adj[w[i]].insert(b);
            }
        }
        for(int i =0; i<n; i++)
        {
            for(int j =0; j<n; j++)
            {c=0;
                for(int k =0; k<w[i].size(); k++)
                {
                    if(w[i][k] != w[j][k])
                    {
                        c++;
                    }
                }
                if(c==1)
                {
                
                    adj[w[i]].insert(w[j]);
                    adj[w[j]].insert(w[i]);
                }
            }
        }
        q.push({0,b});
        dist[b]=0;
        for(auto p:adj)
        {
            cout<<p.first<<" ";
            for(auto x:p.second)
            cout<<x<<" ";
            cout<<endl;
        }
 
        while(!q.empty())
        {
            int d = q.top().first;
            string n = q.top().second;
            q.pop();

            for(auto it: adj[n])
            {                
                if(dist[it] > d+1)
                {
                    dist[it]=d+1;
                    q.push({d+1,it});
                }                
            }
        }
        if(dist[e]==1e9)
        return 0;
        if(ans==false)
        return 0;
        return dist[e]+1;
    }
};