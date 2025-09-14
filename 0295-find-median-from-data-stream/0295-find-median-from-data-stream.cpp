class MedianFinder {
public:
    priority_queue<int> l;
    priority_queue<int,vector<int>,greater<int>> r;
    MedianFinder(){}
    void addNum(int x){
        l.push(x);
        if(!r.empty()&&l.top()>r.top())
        {
            r.push(l.top());
            l.pop();
        }
        if(l.size()>r.size()+1)
        {
            r.push(l.top());
            l.pop();
        }
        else if(r.size()>l.size())
        {
            l.push(r.top());
            r.pop();
        }
    }
    double findMedian(){
        if(l.size()==r.size())
        return(l.top()+r.top())/2.0;
        
        return l.top();
    }
};
