class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]==9){
                digits[i]=0;
            }else{
                digits[i]++;
                return digits;
            }
        }
        vector<int>ans;
        ans.push_back({1});
        for(int i=0;i<digits.size();i++){
            ans.push_back({0});
        }
        return ans;
    }
};