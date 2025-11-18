class Solution {
public:
    int numDecodings(std::string s) {
        if (s.empty() || s[0] == '0') return 0;
        int n = s.length();
        long long w1 = 1; 
        long long w2 = 1; 

        for (int i = 1; i < n; ++i) {
            long long current_ways = 0;
            char current_char = s[i];
            char previous_char = s[i - 1];

            if (current_char != '0') {
                current_ways = w1;
            }
            if (previous_char == '1' || (previous_char == '2' && current_char <= '6')) {
                current_ways += w2;
            }
            if (current_ways == 0) return 0;
            w2 = w1;
            w1 = current_ways;
        }

        return (int)w1;
    }
};