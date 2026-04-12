class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double>ans;
        if(sides[0]+sides[1]<=sides[2] ||sides[1]+sides[2]<=sides[0]||sides[2]+sides[0]<=sides[1])
        return {};
        if((sides[0]+sides[1]>sides[2])&&(sides[0]+sides[2]>sides[1])&&(sides[2]+sides[1]>sides[0]))
        {
            double a=sides[0],b=sides[1],c=sides[2];
            double A=acos((b*b+c*c-a*a)/(2*b*c))*180.0/M_PI, B=acos((a*a+c*c-b*b)/(2*a*c))*180.0/M_PI, C=acos((a*a+b*b-c*c)/(2*a*b))*180.0/M_PI;
        ans={A, B, C};sort(ans.begin(),ans.end());}
        
        return ans;       
    }
};