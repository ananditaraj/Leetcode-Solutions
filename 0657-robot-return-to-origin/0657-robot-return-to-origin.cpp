class Solution {
public:
    bool judgeCircle(string moves) {
        int r=0,l=0,d=0,u=0;
        for(int i=0; i<moves.size(); i++)
        {
            if(moves[i]=='U') u++;
            else if(moves[i]=='D') d++;
            else if(moves[i]=='L')l++;
            else r++;
        }
        return (u==d&&l==r);
        
    }
};