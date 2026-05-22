class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        unordered_map<string,int>mp;
        string curr="", s="";

        for(string i:chunks)
        s+=i;

        int n=s.size();
        for(int i=0; i<n; i++)
        {
            char ch=s[i];

            if(isalpha(ch))
            curr+=ch;
            else if(ch=='-')
            {
                if(curr.size()!=0 && i+1<n && isalpha(s[i+1]))
                curr+='-';
                else{
                    if(curr.size()!=0){
                    mp[curr]++;
                    curr="";
                    }
                }
            }
            else
            {
                if(curr.size()!=0)
                {
                    mp[curr]++;
                    curr="";
                }
            }
        }
        if(curr.size()!=0)
        mp[curr]++;

        vector<int>ans;

        for(string str:queries){
            if(mp.find(str)!=mp.end())ans.push_back(mp[str]);
            else ans.push_back(0);
        }
        return ans;


    }
};