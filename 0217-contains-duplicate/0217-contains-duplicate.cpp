class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>mpp;
        for(auto it:nums){
            if(mpp[it]>=1){
                return true;
            }
            mpp[it]+=1;
        }
        return false;
    }
};