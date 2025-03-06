class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int count = 1 << n;
        vector<vector<int>> a;
        for(int i=0;i<count;i++){
            vector<int> b;
            for(int j=0;j<n;j++){
                if(i & (1 << j)){
                    b.push_back(nums[j]);
                }
            }
            a.push_back(b);
        }
    return a;
    }
};