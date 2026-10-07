class Solution {
public:
    void solve(string& s,int n, string& curr, int& maxLen, int i, int count, unordered_set<string>& st){
        if(count<0) return;
        
        if(i==n){
            if(count==0){
                if(curr.length()>maxLen){
                    maxLen=curr.length();
                    st.clear();
                }
                if(curr.length()==maxLen){
                    st.insert(curr);
                }
            }
            return;
        }

        if(s[i]!='(' && s[i]!=')'){// alpha
            curr.push_back(s[i]);
            solve(s,n,curr,maxLen,i+1,count,st);
            curr.pop_back();
            return;
        } 
        curr.push_back(s[i]);
        solve(s,n,curr,maxLen,i+1,count + (s[i]=='(' ? 1 : -1),st);
        curr.pop_back();

        solve(s,n,curr,maxLen,i+1,count,st);
    }

    vector<string> removeInvalidParentheses(string s) {
        int n=s.length();
        int maxLen=0;
        string curr="";
        unordered_set<string> st;

        solve(s,n,curr,maxLen,0,0,st);

        return vector<string>(st.begin(),st.end());
        
    }
};