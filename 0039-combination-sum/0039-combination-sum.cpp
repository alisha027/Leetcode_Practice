class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result,
                   vector<int>& current, int index) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (candidates[i] <= target) {
                current.push_back(candidates[i]);
                // Since we can reuse the same element, pass 'i' instead of 'i + 1'
                backtrack(candidates, target - candidates[i], result, current, i);
                current.pop_back(); // backtrack
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, result, current, 0);
        return result;
    }
};
