class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
          sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        int i = prices.size() - 1;
        int j = discounts.size() - 1;
        double ans=0;
        while(i>=0)  {
            if(j>=0){
                ans += (double)prices[i] * (100 - discounts[j]) / 100.0;
                j--;
            }else{
                ans+=prices[i];
            }
            i--;
        }
        return ans;
    }
};