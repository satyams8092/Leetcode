class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s.at(i)==')'){
                cnt--;
            }
            if(cnt!=0){
                ans.push_back(s.at(i));
            }
            if(s.at(i)=='('){
                cnt++;
            }
        }
        return ans;
    }
};