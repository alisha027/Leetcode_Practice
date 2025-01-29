class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pur = INT_MAX;
        int pro = INT_MIN;
        int dif = 0;
        for(int i=0;i<prices.size();i++){
            pur = min(pur,prices[i]);
            dif = prices[i]-pur;
            pro = max(pro,dif);
        }
        return pro;
    }
};