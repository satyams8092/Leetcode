class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        int sign = 1;
        int i = 0;
        
        // Skip whitespace
        while(i < s.length() && s[i] == ' ') {
            i++;
        }
        
        // Handle sign
        if(i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Process digits
        while(i < s.length()) {
            char ch = s[i];
            int digit = ch - '0';
            
            if(digit >= 0 && digit <= 9) {
                // Check for overflow
                if(result > INT_MAX/10 || (result == INT_MAX/10 && digit > INT_MAX%10)) {
                    return (sign == 1) ? INT_MAX : INT_MIN;
                }
                result = result * 10 + digit;
            } else {
                break;
            }
            i++;
        }
        
        return result * sign;
    }
};