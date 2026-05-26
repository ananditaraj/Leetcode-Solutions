class Solution {
public:
unordered_map <string,bool>t;
    bool solve(string curr, int i,string news, unordered_map<string,vector<char>>&mp)
    {
        if(curr.length()==1) return true;

        string key=curr+"_"+to_string(i)+"_"+news;
        if(t.count(key))
        return t[key];

        if(news.length() == curr.length()-1)
            return t[key]=solve(news, 0, "", mp);

            if(i >= curr.length()-1)
            return false;

        string pair=curr.substr(i,2);
        if(!mp.count(pair)) return t[key]=false;

        for(char &ch:mp[pair])
        {
            news.push_back(ch);
            if(solve(curr,i+1,news,mp)) return t[key]=true;
            news.pop_back();
        }
        return t[key]=false;

    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        for(int i=0; i<allowed.size(); i++)
        {
            string a=allowed[i].substr(0,2);
            char l=allowed[i][2];
            mp[a].push_back(l);
        }
        return solve(bottom,0,"",mp);
    }
};