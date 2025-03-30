class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> temp;
        int n = nums.size();
        int count = 0;
        int i = 0;
        int j = n-1;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                temp.push_back(i);
                count++;
                break;
            }
        }
        for(int j=n-1;j>=0;j--){
            if(nums[j]==target){
                temp.push_back(j);
                count++;
                break;
            }
        }
        if(count==0){
        temp.push_back(-1);
        temp.push_back(-1);
        }
        return temp;
    }
};