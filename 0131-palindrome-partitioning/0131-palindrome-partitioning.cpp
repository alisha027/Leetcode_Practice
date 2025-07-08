class Solution {
public:
    vector<vector<string>> ans;
    bool checkPalindrome(string& s, int start, int i) {
        while(start < i) {
            if(s[start] != s[i]) {
                return false;
            }
            start++;
            i--;
        }
        return true;
    }
    void backtrack(string& s, int start, vector<string>& temp) {
        if(start == s.length()) {
            ans.push_back(temp);
            return; 
        }
        for(int i = start; i < s.length(); i++) {
            if(checkPalindrome(s, start, i)) {
                temp.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1, temp);
                temp.pop_back(); 
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        backtrack(s, 0, temp);
        return ans;
    }
};
