class Solution {
public:

    void generateparenthesis(int n,vector<string> &ans,int open,int close,string s){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        if(open < n){
            generateparenthesis(n,ans,open+1,close,s+"(");
        }
        if(close < open){
            generateparenthesis(n,ans,open,close+1,s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateparenthesis(n,ans,0,0,"");
        return ans;
    }
};