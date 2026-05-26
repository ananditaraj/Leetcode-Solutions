class Solution {
public:
     vector<int>divisors(int x)
    {
        vector<int> v;
        for(int i=1;i*i<=x; i++)
        {
            if(x%i==0)
            {
                v.push_back(i);
                if(i!=x/i)
                    v.push_back(x/i);
            }
            if(v.size()>4)
                break;
        }
        return v;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int x:nums)
        {
            vector<int>d=divisors(x);
            if(d.size()==4)
            {
                for(int v:d)
                sum+=v;
            }
        }
        return sum;
    }
};