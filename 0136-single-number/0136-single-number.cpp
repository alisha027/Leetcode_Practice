class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        // int xo = 0;
        // for(int i=0;i<n;i++){
        //    xo = xo ^ nums[i];
        // }
        // return xo;  
        unordered_map<int,int> temp;
        for(int i : nums){
            temp[i]++;
        } 
        for(auto &i : temp){
            if(i.second==1){
                return i.first;
            }
        }
        return -1; 
    }
};