class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<int> col(n, 0), diag1(2 * n, 0), diag2(2 * n, 0);

        function<void(int)> backtrack = [&](int row) {
            if (row == n) {
                result.push_back(board);
                return;
            }

            for (int c = 0; c < n; ++c) {
                if (col[c] || diag1[row + c] || diag2[row - c + n])
                    continue;

                board[row][c] = 'Q';
                col[c] = diag1[row + c] = diag2[row - c + n] = 1;

                backtrack(row + 1);

                board[row][c] = '.';
                col[c] = diag1[row + c] = diag2[row - c + n] = 0;
            }
        };

        backtrack(0);
        return result;
    }
};
