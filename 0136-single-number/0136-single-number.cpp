class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(int it:nums){
            xorr=xorr^it;
        }
        return xorr;
    }
};