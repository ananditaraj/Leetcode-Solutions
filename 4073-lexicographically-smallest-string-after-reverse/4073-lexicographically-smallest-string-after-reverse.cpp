class Solution {
public:
    string lexSmallest(string s) {
        int n=s.size();
    string best = s;

    for (int k=1; k<=n; k++) {
        string t1 = s;
        reverse(t1.begin(),t1.begin()+k);
        best=min(best,t1);

        string t2=s;
        reverse(t2.end()-k,t2.end());
        best=min(best,t2);
    }
    return best;        
    }
};