class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = left + (right - left) / 2, time = 0;
            for (int bananas : piles) 
                time += (bananas + mid - 1) / mid;
            if (time > h) 
                left = mid + 1;
            else 
                right = mid;
        }
        return left;
    }
};
