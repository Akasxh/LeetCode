class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size_prices = prices.size();
        int max_profit = 0,today_profit=0;
        int least_val=numeric_limits<int>::max();
        vector<int> profit(size_prices);
        for(int i=0;i<size_prices;i++){
          int x=prices[i];
          if(x<least_val)least_val=x;
          today_profit = x - least_val;
          if(max_profit<today_profit)max_profit = today_profit;
        }
        if(max_profit>0)return max_profit;
        if(max_profit<=0) return 0;
        return 0;
    }
};