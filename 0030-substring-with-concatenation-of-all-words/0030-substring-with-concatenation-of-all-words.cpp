class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || s.empty()) return res;

        int n = s.size();
        int m = words.size();
        int w = words[0].size();
        int totalLen = m * w;

        unordered_map<string, int> need;
        for (auto &x : words) need[x]++;

        for (int offset = 0; offset < w; offset++) {
            int left = offset, count = 0;
            unordered_map<string, int> window;

            for (int right = offset; right + w <= n; right += w) {
                string word = s.substr(right, w);

                if (need.count(word)) {
                    window[word]++;
                    count++;

                    while (window[word] > need[word]) {
                        string leftWord = s.substr(left, w);
                        window[leftWord]--;
                        left += w;
                        count--;
                    }

                    if (count == m) {
                        res.push_back(left);
                        string leftWord = s.substr(left, w);
                        window[leftWord]--;
                        left += w;
                        count--;
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right + w;
                }
            }
        }
        return res;
    }
};
