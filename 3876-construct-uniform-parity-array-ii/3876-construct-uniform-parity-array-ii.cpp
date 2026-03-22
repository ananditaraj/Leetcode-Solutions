#define ll long long
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        ll n=nums1.size(), e=INT_MAX,o=INT_MAX, ce=0,co=0;
        if(*min_element(nums1.begin(), nums1.end())==1)
        return true;
        for(ll i:nums1)
        {
            if(i%2==0)
            {ce++;e=min(e,i);
            }
            if(i%2!=0)
            {co++;o=min(o,i);}
        }
        if(ce==n ||co==n)
        return true;
        else if(e<o)
        return false;
        else return true;


    }
};