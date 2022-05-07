#include <vector>
/*
* array
* complexity = O(n)
* 這題使用到的是 kadane algorithm 的觀念，這個 algo 用了 dynamic programming...
*/
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price = prices[0];
        int sell_price = 0;
        int max_profit = 0;
        for (int price : prices){
            if (buy_price > price){
                buy_price = price;
                sell_price = price;
            }else if (sell_price < price){
                sell_price = price;
            }
            if (sell_price - buy_price > max_profit){
                max_profit = sell_price - buy_price;
            }
        }
        return max_profit;
    }
};