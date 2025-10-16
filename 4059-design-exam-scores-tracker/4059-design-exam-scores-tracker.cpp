class ExamTracker {
public:
    map<int,long long>mp; 
    int last;
    ExamTracker() {
        last =0;
    }
    
    void record(int time, int score) {
        mp[time]+=mp[last]+score;     
        last =time;       
    }
    
    long long totalScore(int startTime, int endTime) {
        int total =0;
        if(mp.empty()) return 0;

        auto ite = mp.upper_bound(endTime);
        if(ite ==mp.begin())
        return 0;
        --ite;
        long long es=ite->second;

        auto its =mp.lower_bound(startTime);
        long long ss=0;

        if(its!= mp.begin())
        {
            --its;
            ss=its->second;
        }     
        
        return es-ss;
        
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */