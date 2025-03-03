class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s){
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }else{
            if(st.empty()){
                return false;
            }
            char t = st.top();
            if(ch==')' && t=='(' || ch == '}' && t=='{' || ch == ']' && t == '['){
                st.pop();
            }else{
                return false;
            }
        }
        }
        return st.empty();
    }
};
