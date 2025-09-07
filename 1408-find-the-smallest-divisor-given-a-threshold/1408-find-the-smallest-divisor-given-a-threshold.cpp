class Solution {
public:
    int calSum(vector<int>&nums, int th, int mid){
        int sum = 0;
        for(auto it : nums){
            sum += (it + mid - 1) / mid;  // Fixed: was sum=+ instead of sum+=
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;           // Fixed: should start from 1, not min element
        int high = *max_element(nums.begin(), nums.end());  // Fixed: proper way to find max
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            int sum = calSum(nums, threshold, mid);
            
            if(sum <= threshold){
                high = mid - 1;     // This divisor works, try smaller ones
            } else {
                low = mid + 1;      // Fixed: was mid-1, should be mid+1
            }
        }
        return low;
    }
};