class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rows[9];
        unordered_set<int> cols[9];
        unordered_set<int> submat[9];

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int val = board[i][j];
                if(val=='.'){
                    continue;
                }
                if(rows[i].find(val)!=rows[i].end()){
                    return false;
                }
                rows[i].insert(val);
                if(cols[j].find(val)!=cols[j].end()){
                    return false;
                }
                cols[j].insert(val);
                int index = (i/3)*3 + j/3;
                if(submat[index].find(val)!=submat[index].end()){
                    return false;
                }
                submat[index].insert(val);
            }
        }
        return true;
    }
};