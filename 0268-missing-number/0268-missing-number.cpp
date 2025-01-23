class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        int n=nums.size();
        int sum2 = 0;
        for(int i=0;i<=n;i++){
            sum2 += i;
        }
        int c = sum2-sum;
        return c;
    }
};