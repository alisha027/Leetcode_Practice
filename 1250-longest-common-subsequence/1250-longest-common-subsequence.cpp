class Solution {
public:
    int recSubseq(string& text1,int n,string& text2,int m,vector<vector<int>>& memo){
        if(n==0 || m==0){
            return 0;
        }
        if(memo[n][m] != -1){
            return memo[n][m];
        }
        if(text1[n-1]==text2[m-1]){
            memo[n][m] = 1 + recSubseq(text1,n-1,text2,m-1,memo);
        }else{
            memo[n][m] = max(recSubseq(text1,n-1,text2,m,memo),recSubseq(text1,n,text2,m-1,memo));
        }
        return memo[n][m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> memo(n+1,vector<int>(m+1,-1));
        int ans = recSubseq(text1,n,text2,m,memo);
        return ans;
    }
};