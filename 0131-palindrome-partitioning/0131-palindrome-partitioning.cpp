class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }

    void func(vector<vector<string>>& ans, vector<string>& part,string& s,int idx){
        if(idx==s.length()){
            ans.push_back(part);
            return;
        }

        for(int i=idx;i<s.length();i++){
            if(isPalindrome(s,idx,i)){
                part.push_back(s.substr(idx,i-idx+1));
                func(ans,part,s,i+1);
                part.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        func(ans,part,s,0);
        return ans;
        
    }
};