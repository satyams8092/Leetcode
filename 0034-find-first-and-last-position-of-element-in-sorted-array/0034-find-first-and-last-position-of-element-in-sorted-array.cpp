class Solution {
    int binSearch(vector<int>& nums, int target, bool left) {
        int s = 0, e = nums.size() - 1;
        int result = -1;

        while (s <= e) {  // Use s <= e to ensure you check the entire array
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                result = mid;
                if (left) {
                    e = mid - 1;  // Move left to find the first occurrence
                } else {
                    s = mid + 1;  // Move right to find the last occurrence
                }
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return result;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);  // Default answer in case target is not found
        
        int first = binSearch(nums, target, true);  // Find the leftmost index
        if (first == -1) return ans;  // Target is not found

        int last = binSearch(nums, target, false);  // Find the rightmost index
        
        ans[0] = first;
        ans[1] = last;
        return ans;
    }
};
