class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0; // Base case: x^0 = 1
        if (n < 0) {
            x = 1 / x;  // Convert x^(-n) to (1/x)^n
            if (n == INT_MIN) { // Handle edge case of INT_MIN
                n += 1;
                return x * myPow(x, -n);
            }
            n = -n;
        }
        
        double result = 1.0;
        while (n > 0) {
            if (n % 2 == 1) result *= x; // If n is odd, multiply x once
            x *= x;  // Square x
            n /= 2;  // Reduce exponent by half
        }
        
        return result;
    }
};
