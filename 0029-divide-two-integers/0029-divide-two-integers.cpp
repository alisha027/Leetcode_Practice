class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        
        long long a = abs((long long)dividend), b = abs((long long)divisor), res = 0;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        
        while (a >= b) {
            long long temp = b, multiple = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            res += multiple;
        }
        
        return sign * res;
    }
};
