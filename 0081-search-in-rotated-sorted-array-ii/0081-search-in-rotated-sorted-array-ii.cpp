class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = static_cast<int>(nums.size()) - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2; // avoids overflow
            if (nums[mid] == target) return true;

            // Skip duplicates at both ends
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                ++low;
                --high;
                continue;
            }

            // Left half sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else { // Right half sorted
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
