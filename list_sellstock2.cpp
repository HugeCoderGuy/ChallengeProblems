/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. 
However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_gain = 0;
        int holding_price = prices[0];
        int next_day;
        int next_next_day;
        for (int i=0; i<prices.size()-2 && prices.size() > 1; i++) {
            while (i+1<prices.size() && prices[i+1] > prices[i]) {
                i++;
            }
            if (prices[i] > holding_price) {
                // Here we sell
                max_gain += prices[i] - holding_price;
                auto it = max_element(std::begin(prices), std::end(prices));
                holding_price = *it;
            }
            while (i+2<prices.size() && prices[i+2] < prices[i+1]) {
                // now we find the next point we want to buy
                i++;
            }
            if (i<prices.size()-1){
                holding_price = prices[i+1];
            }
            
        }
        if (prices.size() == 2 && prices[1] > prices[0]) {
            max_gain = prices[1] - prices[0];
        }
        else if (prices.size() >= 3 && prices[prices.size()-1] > prices[prices.size()-2] && prices[prices.size()-3] >= prices[prices.size()-2]) {
            max_gain += prices[prices.size()-1] - prices[prices.size()-2];
        }


        return max_gain;
    }
};
