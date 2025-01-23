class Solution {
public:
    int reverse(int x) {
        int num = 0;
        int rev = 0;
        while(x!=0){
            num=x%10;
            if(rev>INT_MAX/10 || rev<INT_MIN/10){
            return 0;
            }
            rev = rev*10 + num;
            x = x/10;
        }
        return rev; 
    }
};