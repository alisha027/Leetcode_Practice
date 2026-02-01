// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int len = nums1.size();
//         int m = nums2.size();
//         for(int i=0;i<m;i++){
//             nums1.push_back(nums2[i]);
//         }
//         sort(nums1.begin(),nums1.end());
//         int k = nums1.size();
//         double median = 0;
//         if(k%2==0){
//             median = (nums1[k/2] + nums1[(k/2)-1])/2.0;
//         }else {
//             median = nums1[((k+1)/2)-1];
//         }
//         return median;
//     }
// };

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        int i=0;
        int j=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<nums2[j]){
                temp.push_back(nums1[i]);
                i++;
            }
            else{
                temp.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            temp.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            temp.push_back(nums2[j]);
            j++;
        }
        int n=temp.size();
        if(n%2!=0){
            return temp[n/2];
        }
        else{
            return (temp[n/2]+temp[n/2 -1])/2.0;
        }
    }
};