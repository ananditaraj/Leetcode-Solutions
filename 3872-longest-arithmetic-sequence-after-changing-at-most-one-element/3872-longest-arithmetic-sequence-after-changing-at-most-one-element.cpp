class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n=nums.size();
        vector<int>l(n,2);
        vector<int>r(n,2);

        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
               l[i]=l[i-1]+1;
        }

        for(int i=n-3;i>=0;i--){
            if(nums[i+1]-nums[i]==nums[i+2]-nums[i+1])
                r[i]=r[i+1]+1;
        }

        int ans=2;
        for(int i=0;i<n;i++){   
            if(i==0)
                ans=max(ans,r[i+1]+1);
            
           else if(i==n-1)
                ans=max(ans,l[i-1]+1);
                else{        
            
                ans=max(ans,l[i-1]+1);
                ans=max(ans,r[i+1]+1);
               int leftlen=1;
               int  rightlen=1;
                if((nums[i+1]+nums[i-1])%2==0){
                    int req=(nums[i+1]-nums[i-1])/2;
                    if(i>=2 && nums[i-1]-nums[i-2]==req)
                        leftlen=l[i-1];
                    
                    if(i<=n-3 && (nums[i+2]-nums[i+1])==req)
                        rightlen=r[i+1];                    
                }
                ans=max(ans,leftlen+rightlen+1);
                }            
        }

        return ans;
    }
};