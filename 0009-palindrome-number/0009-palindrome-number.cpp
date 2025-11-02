class Solution {
public:
    int reverse(int x) {
        int y=0;
        while(x!=0){
            int r=x%10;
            if ((y > INT_MAX/10) || (y < INT_MIN/10) ) return 0;
            x=x/10;
            y=(y*10)+r;
        }
        return y;
    }
    bool isPalindrome(int x) {
        if(x<0) return false;
        int n=x;
        int r=reverse(x);
        return (n==r);
    }
};