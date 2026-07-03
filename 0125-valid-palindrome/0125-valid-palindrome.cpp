class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(char c:s){
            if(isalnum(c)){
                str+=tolower(c);
            }
        }
        int low=0;
        int high=str.length()-1;
        while(low<high){
            if(str[low]!=str[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
};