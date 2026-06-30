class Solution {
public:
bool check(long long sum,int x){
        int a=sum%10;
        if(a!=x)return false;
        int b=0;
        while(sum>0){
            b=sum%10;
            sum/=10;
        }
        return b==x;
    }

    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size(), ans=0;
        vector<long long>p(n,0);
        p[0]=nums[0];
        for(int i=1; i<n; i++)
        p[i]=p[i-1]+nums[i];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                long long sum=p[j];
                if(i>0)
                sum-=p[i-1];
                if(check(sum,x))
                ans++;
            }
        }
        return ans;
        
    }
};