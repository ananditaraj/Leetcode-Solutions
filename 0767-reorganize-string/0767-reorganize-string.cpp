class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();

        vector<int> freq(26,0);
        for(char c:s)
        freq[c-'a']++;

        priority_queue<pair<int,char>>pq;
        for(int i = 0; i < 26; i++)
            if(freq[i] > 0)
                pq.push({freq[i], char(i + 'a')});
        
        if(pq.top().first > (n + 1) / 2)
            return "";
        
        string ans = "";
        
        while(pq.size() > 1) {
            auto [f1, c1] = pq.top(); pq.pop();
            auto [f2, c2] = pq.top(); pq.pop();
            
            ans += c1;
            ans += c2;            
            if(--f1 > 0) pq.push({f1, c1});
            if(--f2 > 0) pq.push({f2, c2});
        }
        
        if(!pq.empty())
            ans += pq.top().second;
        
        return ans;
    }
};