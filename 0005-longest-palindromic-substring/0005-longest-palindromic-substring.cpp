class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, maxLen = 0;
        
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            return make_pair(left + 1, right - left - 1);
        };
        
        for (int i = 0; i < n; i++) {
            auto [oddStart, oddLen] = expand(i, i);
            if (oddLen > maxLen) {
                start = oddStart;
                maxLen = oddLen;
            }
            
            auto [evenStart, evenLen] = expand(i, i + 1);
            if (evenLen > maxLen) {
                start = evenStart;
                maxLen = evenLen;
            }
        }
        
        return s.substr(start, maxLen);
    }
};
