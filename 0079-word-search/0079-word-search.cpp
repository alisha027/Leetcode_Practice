class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        function<bool(int,int,int)> dfs = [&](int r, int c, int idx) {
            if (idx == word.size()) return true;                 
            if (r < 0 || r >= m || c < 0 || c >= n) return false;
            if (board[r][c] != word[idx]) return false;

            char temp = board[r][c];
            board[r][c] = '#';                                  

            bool found =  dfs(r+1, c, idx+1) ||
                          dfs(r-1, c, idx+1) ||
                          dfs(r, c+1, idx+1) ||
                          dfs(r, c-1, idx+1);

            board[r][c] = temp;                                 
            return found;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};
