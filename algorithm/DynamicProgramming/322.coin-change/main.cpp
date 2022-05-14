#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (int i = 1; i < dp.size(); i++){

            int fewest = -1;
            bool has_combination = false;
            for (int j = 0; j < coins.size(); j++){
                if (i >= coins[j]){
                    if (has_combination){
                        if ((dp[i - coins[j]] >= 0 ) && 
                            (dp[i - coins[j]] + 1 < fewest)){
                            fewest = dp[i - coins[j]] + 1;
                        }
                    }else {
                        if (dp[i - coins[j]] >= 0){
                            fewest = dp[i - coins[j]] + 1;
                            has_combination = true;
                        }
                    }
                }
            }
            dp[i] = fewest;
        }

        return dp[amount];
    }
};
int main () {
    Solution s;
    vector<int> coins{1,2,5};
    int amount = 11;
    int fewest = s.coinChange(coins, amount);
    cout << fewest;
}