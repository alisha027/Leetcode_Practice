class Solution {
public:
    int dp(int i, int j, string& s, vector<vector<int>>& memo) {
        if (i > j) return 0;
        if (i == j) return 1;

        if (memo[i][j] != -1) return memo[i][j];

        if (s[i] == s[j])
            memo[i][j] = 2 + dp(i + 1, j - 1, s, memo);
        else
            memo[i][j] = max(dp(i + 1, j, s, memo), dp(i, j - 1, s, memo));

        return memo[i][j];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dp(0, n - 1, s, memo);
    }
};
