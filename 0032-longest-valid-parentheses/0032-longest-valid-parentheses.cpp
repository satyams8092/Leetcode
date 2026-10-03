class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> st;
        st.push(-1);                    // ✅ base index

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);             // push index
            } else {
                st.pop();               // pop matching '(' or base
                if(st.empty()){
                    st.push(i);         // ✅ new base at unmatched ')'
                } else {
                    res = max(res, i - st.top());  // ✅ length from base
                }
            }
        }
        return res;
    }
};