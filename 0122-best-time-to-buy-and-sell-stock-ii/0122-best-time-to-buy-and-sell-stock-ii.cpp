class Solution {
public:
    int solve(vector<int>& prices, int index, int buy, vector<vector<int>>& memo) {
        if(index == prices.size()) return 0;
        if(memo[index][buy] != -1){
            return memo[index][buy];
        }

        int profit = 0;
        if(buy) {
            int buyProfit = solve(prices, index + 1, 0, memo) - prices[index];
            int skip = solve(prices, index + 1, 1, memo);
            profit = max(buyProfit, skip);
        } else {
            int sellProfit = prices[index] + solve(prices, index + 1, 1, memo);
            int skip = solve(prices, index + 1, 0, memo);
            profit = max(sellProfit, skip);
        }
        memo[index][buy] = profit;
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n + 1, vector<int>(3, -1));  
        return solve(prices, 0, 1, memo);  
    }
};


// class Solution{
//     public:
//     int maxProfit(vector<int>& prices){
//         int x = prices[0];
//         int sum = 0;
//         for(int i=1;i<n;i++){
//             if(prices[i] > x){
//                 ans = ans + (prices[i]-x);
//             }
//             x = prices[i];
//         }
//     }
// };
