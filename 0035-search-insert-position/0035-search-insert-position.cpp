class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        if(target<nums[i]){
            return 0;
        }
        if(target>nums[j]){
            return (j+1);
        }
        else{
            while(i<j){
                int mid=(i+j)/2;
                if(nums[mid]==target){
                    return mid;
                }
                if(nums[i+1]==nums[j]){
                    return (i+1);
                }
                if(nums[mid]<target){
                    i=mid;
                }
                if(nums[mid]>target){
                    j=mid;
                }
            }
            return 0;
        }
    }
};