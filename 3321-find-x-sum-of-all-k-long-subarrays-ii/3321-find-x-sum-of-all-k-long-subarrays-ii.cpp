#define ll long long
class Solution {
public:
    ll sum=0;
    set<pair<int,int>>main;
    set<pair<int,int>>rem;

    void insertInSet(const pair<int,int>& p,int x) {
        if(main.size()<x || p>*main.begin()) {
            sum+= 1LL*p.first* p.second;
            main.insert(p);

            if(main.size()>x) {
                auto s = *main.begin();
                sum-=1LL*s.first * s.second;
                main.erase(s);
                rem.insert(s);
            }
        } else
            rem.insert(p);
    }

    void removeFromSet(const pair<int, int>& p, int x) {
        if(main.find(p) !=main.end()) {
            sum -=1LL*p.first*p.second;
            main.erase(p);

            if(!rem.empty()) {
                auto l=*rem.rbegin();
                rem.erase(l);
                main.insert(l);
                sum+=1LL*l.first*l.second;
            }
        } else
            rem.erase(p);
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        ll n=nums.size();
        sum=0;
        vector<ll>ans;        
        unordered_map<int, int> mp;

        int i=0,j=0;
        while(j<n) {
            if(mp[nums[j]]>0)
                removeFromSet({mp[nums[j]],nums[j]},x);

            mp[nums[j]]++;
            insertInSet({mp[nums[j]],nums[j]}, x);

            if((j-i+1)==k) {
                ans.push_back(sum);

                removeFromSet({mp[nums[i]],nums[i]}, x);
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                else
                    insertInSet({mp[nums[i]], nums[i]}, x);
                i++;
            }
            j++;
        }
        return ans;
    }
};