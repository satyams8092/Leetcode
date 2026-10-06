class Solution {
public:
    int minAddToMakeValid(string s) {
        int res=0;
        stack<char> st;
        for(char ch:s){
            if(ch=='('){
                st.push(ch);
            }else{
                if(st.empty()){
                    res++;
                }else{
                    st.pop();
                }
            }
        }
        res+=st.size();
        return res;
    }
};