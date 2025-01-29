class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> temp;
        for(int i : nums){
            temp[i]++;
        }
        for(auto i : temp){
            if(i.second > nums.size()/2){
                return i.first;
            }
        }
        return -1;
    }   
};