class Solution {
public:
    static bool compare(string a, string b) {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back(to_string(nums[i]));
        }
        sort(temp.begin(),temp.end(),compare);
        if(temp[0]=="0"){
            return "0";
        }
        string s;
        for(int i=0;i<temp.size();i++){
            s = s + temp[i];
        }
        return s;
    }
};