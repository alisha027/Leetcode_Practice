// class Solution {
// public:
//     void lettercomb(string &digits,int index,string temp,vector<string> &ans,vector<string> &pos){
//         if(digits.size()==)
//     }
//     vector<string> letterCombinations(string digits) {
//         if(digits.length()==0){
//             return {};
//         }
//     }   
//     vector<string> pos = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//     vector<string> ans;
//     lettercomb(digits,0,"",ans,pos);
//     return ans;
//     }
// };
class Solution {
public:
    void lettercomb(string &digits, int index, string temp, vector<string> &ans, vector<string> &pos) {
        if (index == digits.size()) {  
            ans.push_back(temp);
            return;
        }

        string letters = pos[digits[index] - '0'];  
        for (char ch : letters) {  
            lettercomb(digits, index + 1, temp + ch, ans, pos);  
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};  

        vector<string> pos = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
        vector<string> ans;
        lettercomb(digits, 0, "", ans, pos);  
        return ans;
    }
};
