class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int p=prices.size(), d=discounts.size();
        sort(prices.rbegin(),prices.rend());int j;
        sort(discounts.rbegin(),discounts.rend()); double ans=0;
        for(int i=0; i<min(p,d); i++)
        {
            ans+=prices[i]*((100-discounts[i])/100.0);
            j=i;
        }
        if(p>d)
        {
            for(int k=j+1; k<p; k++)
            ans+=prices[k];
        }
        return ans;        
    }
};