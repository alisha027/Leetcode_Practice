class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string token;

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(token);
            }
        }

        if (stack.empty()) return "/";

        string result;
        for (string &dir : stack) {
            result += "/" + dir;
        }
        return result;
    }
};
