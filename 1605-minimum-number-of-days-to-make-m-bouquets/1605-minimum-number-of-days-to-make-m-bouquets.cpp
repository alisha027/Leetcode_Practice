class Solution {
public:
    bool bouque(vector<int>& bloomDay,int m, int k, int day) {
        int n = bloomDay.size();
        int total = 0;
        for(int i=0;i<n;i++){
            int count = 0;
            while(i < n && count < k && bloomDay[i] <= day){
                count++;
                i++;
            }
            if(count==k){
                total++;
                i--;
            }
            if(total >= m){
                return true;
            }
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k > n){
            return -1;
        }
        int low = 1, high = 10000000000;
        while(low < high) {
            int mid  = low + (high-low) / 2;
            if(bouque(bloomDay,m,k,mid)){
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};