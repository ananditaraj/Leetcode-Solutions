class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;
        for (int x : a) 
        {
            bool d = false;
            while (!s.empty() && s.top() > 0 && x < 0) 
            {
                if (abs(s.top()) < abs(x)) 
                {
                    s.pop();
                    continue;
                } 
                else if (abs(s.top()) == abs(x))
                    s.pop();
                
                d = true;
                break;
            }
            if (!d)
                s.push(x);
        }
        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
