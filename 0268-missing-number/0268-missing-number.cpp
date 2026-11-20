class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1=0;
        int xor2=0;

        for (int i=1;i<=nums.size();i++){
            xor1=xor1^i;
        }
        for(auto it:nums){
            xor2=xor2^it;
        }
        return xor1^xor2;
    }
};