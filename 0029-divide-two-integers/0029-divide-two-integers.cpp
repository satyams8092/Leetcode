class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX; 
        if(dividend == divisor) return 1;

        bool sign = true;
        if(dividend >= 0 && divisor < 0) sign = false;
        if(dividend <= 0 && divisor > 0) sign = false;

        long n = abs((long)dividend);
        long d = abs((long)divisor);
        long ans = 0;

        while(n >= d){
            int cnt = 0;
            while(cnt < 31 && n >= (d << (cnt+1))){  
                cnt++;
            }
            ans += (1L << cnt);
            n -= d << cnt;
        }

        return sign ? ans : -ans;
    }
};