// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> nse(n,n);
//         stack<int> st;
//         for(int i=n-1;i>=0;i--){
//             while(!st.empty() && heights[st.top()]>=heights[i]){
//                 st.pop();
//             }
//             if(!st.empty()){
//                 nse.push_back(st.top());
//             }
//             st.push(i);
//         }
//         //reverse(nse.begin(),nse.end());
//         vector<int> pse(n,-1);
//         stack<int> st2;
//         for(int i=0;i<n;i++){
//             while(!st2.empty() && heights[st2.top()]>=heights[i]){
//                 st2.pop();
//             }
//             if(!st2.empty()){
//                 pse.push_back(st.top());
//             }
//             st2.push(i);
//         }
//         //reverse(pse.begin(),pse.end());
//         int max1 = 0;
//         for(int i=0;i<n;i++){
//             int area = (nse[i]-pse[i]-1)*heights[i];
//             max1 = max(max1,area);
//         }
//         return max1;
//     }
// };

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n, n);  // Initialize NSE with n (right boundary)
        vector<int> pse(n, -1); // Initialize PSE with -1 (left boundary)
        stack<int> st;

        // Compute Next Smaller Element (NSE) index
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                nse[st.top()] = i; // Store correct NSE index
                st.pop();
            }
            st.push(i);
        }

        // Clear stack for PSE calculation
        while (!st.empty()) {
            st.pop();
        }

        // Compute Previous Smaller Element (PSE) index
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                pse[st.top()] = i; // Store correct PSE index
                st.pop();
            }
            st.push(i);
        }

        // Calculate Maximum Rectangle Area
        int max1 = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = width * heights[i];
            max1 = max(max1, area);
        }

        return max1;
    }
};

        