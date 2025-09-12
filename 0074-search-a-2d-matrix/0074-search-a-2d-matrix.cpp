class Solution {
public:
    bool search(vector<int>& nums,int target){
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return true;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            bool isFound=search(matrix[i],target);
            if(isFound){
                return true;
            }
        }
        return false;
    }
};