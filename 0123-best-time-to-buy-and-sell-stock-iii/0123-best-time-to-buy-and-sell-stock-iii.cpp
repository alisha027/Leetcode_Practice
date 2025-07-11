class Solution {
public:
    int solve(vector<int>& prices, int index, int buy, int transactionsLeft, vector<vector<vector<int>>>& memo) {
        if(index == prices.size() || transactionsLeft == 0) return 0;

        if(memo[index][buy][transactionsLeft] != -1) {
            return memo[index][buy][transactionsLeft];
        }

        int profit = 0;
        if(buy) {
            int buyProfit = solve(prices, index + 1, 0, transactionsLeft, memo) - prices[index];
            int skip = solve(prices, index + 1, 1, transactionsLeft, memo);
            profit = max(buyProfit, skip);
        } else {
            int sellProfit = prices[index] + solve(prices, index + 1, 1, transactionsLeft - 1, memo);
            int skip = solve(prices, index + 1, 0, transactionsLeft, memo);
            profit = max(sellProfit, skip);
        }

        memo[index][buy][transactionsLeft] = profit;
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxTransactions = 2;
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(2, vector<int>(maxTransactions + 1, -1)));
        return solve(prices, 0, 1, maxTransactions, memo);
    }
};
