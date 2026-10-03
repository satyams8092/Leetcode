class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> sum(n);
        for(int i=0;i<n;i++){
            if(i==0){
                sum[i]=nums[i];
            }else{
                sum[i]=nums[i]+sum[i-1];
            }
        }
        return sum;
    }
};