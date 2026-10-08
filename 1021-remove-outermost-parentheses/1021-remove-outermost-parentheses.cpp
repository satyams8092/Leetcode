class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string res="";
        for(char ch:s){
            if(ch==')') cnt--;
            if(cnt!=0) res.push_back(ch);
            if(ch=='(') cnt++; 
        }
        return res;
    }
};