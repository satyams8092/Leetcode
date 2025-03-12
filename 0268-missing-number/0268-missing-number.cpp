class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int max=nums.size();
        int sum1=(max*(max+1))/2;
        int sum2=0;
        for(int it:nums){
            sum2+=it;
        }
        return(sum1-sum2);
    }
};