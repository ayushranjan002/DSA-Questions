class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        bool sign = (dividend < 0) == (divisor < 0);

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long q = 0;

        while(n >= d) {  
            int cnt = 0;  

            // Find the largest multiple of `d` that fits in `n` using bitwise shifts  
            while(n >= (d << (cnt + 1))) {  
                cnt++;  
            }  

            // Add the corresponding power of 2 to the quotient  
            q += 1LL << cnt;  

            // Subtract the found multiple from `n`  
            n -= (d << cnt);  
        }  

        if(q >= (1LL << 31)) return sign ? INT_MAX : INT_MIN;
        return sign ? q : -q;
    }
};
