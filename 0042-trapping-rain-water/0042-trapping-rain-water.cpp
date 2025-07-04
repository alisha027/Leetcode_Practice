class Solution {
public:
    int trap(vector<int>& height) {
        // int n = height.size();
        // if(n==0)
        //  return 0; 

        // int i = 0;
        // int j = n - 1;
        // int h1 = 0; 
        // int h2 = 0; 
        // int tot = 0;

        // while(i<j){
        //     if(height[i]<height[j]){
        //         if(height[i]>=h1){
        //             h1 = height[i]; 
        //         }else{
        //             tot = tot + (h1 - height[i]); 
        //         }
        //         i++; 
        //     }else{
        //         if(height[j]>=h2){
        //             h2 = height[j]; 
        //         }else{
        //             tot = tot + (h2 - height[j]); 
        //         }
        //         j--; 
        //     }
        // }

        // return tot;
        int n = height.size();
        if(n==0){
            return 0;
        }
        vector<int> leftMax;
        vector<int> rightMax;
        int max1 = height[0];
        for(int i=0;i<n;i++){
            max1 = max(max1,height[i]);
            leftMax.push_back(max1);
        }
        int max2 = height[n-1];
        for(int i=n-1;i>=0;i--){
            max2 = max(max2,height[i]);
            rightMax.push_back(max2);
        }
        reverse(rightMax.begin(),rightMax.end());
        int tot = 0;
        int min1 = 0;
        for(int i=0;i<n;i++){
            min1 = min(leftMax[i],rightMax[i]);
            tot = tot + (min1-height[i]);
        }
        return tot;
    }
};
