class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& c, int e) {
        int n =c.size();
        priority_queue<pair<double,int>>q;
        double ans=0;

        for(int i =0; i<n; i++)
        {
            double p = c[i][0];
            double t = c[i][1];

            double diff= ((p+1.0)/(t+1.0))-(p/t);

            q.push({diff,i});            
        }
        while(e--)
        {
            
        double d = q.top().first;
        int i = q.top().second;

        c[i][0]++;
        c[i][1]++;
        q.pop();

        double diff = (c[i][0]+1.0)/(c[i][1]+1.0) - (double)(c[i][0])/(c[i][1]);
        q.push({diff,i});
        } 
        for(int i =0; i<n; i++)
        {
            double p = c[i][0];
            double t = c[i][1];
            ans+= (double)p/t;
        }
        return ans/n;        
    }
};