class EventManager {
public:
unordered_map<int,int>mp;
priority_queue<pair<int,int>>pq;
    EventManager(vector<vector<int>>& events) {
        for(auto &e:events)
        {
            mp[e[0]]=e[1];
            pq.push({e[1],-e[0]});
        }
        
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId]=newPriority;
        pq.push({newPriority,-eventId});
        
    }
    
    int pollHighest() {
        while(!pq.empty())
        {
            auto[pr,id]=pq.top();
            if(mp.count(-id)&&mp[-id]==pr)
            {
                pq.pop();mp.erase(-id);
                return -id;
            }
            pq.pop();

        }
        return -1;
        
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */