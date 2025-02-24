class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> temp;
        int maxlen = 0;
        int j = 0;
        for(int i=0;i<n;i++){
            temp[s[i]]++;

            while(temp[s[i]]>1){
                temp[s[j]]--;
                j++;
            }

            maxlen = max(maxlen,i-j+1);
        }
        return maxlen;
    }     
};
