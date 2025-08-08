class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int leftSum=0;
        int rightSum=0;
        int n=nums.size();
        for(auto it:nums){
            rightSum+=it;
        }
        for(int i=0;i<n;i++){
            rightSum-=nums[i];
            if(rightSum==leftSum){
                return i;
            }else{
                leftSum+=nums[i];
            }
        }
        return -1;
    }
};