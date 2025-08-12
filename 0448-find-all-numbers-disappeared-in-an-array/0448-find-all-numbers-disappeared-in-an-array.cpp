class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n + 1, 0); // initialize with zeros
        vector<int> ans;

        // Count occurrences
        for (int it : nums) {
            arr[it] += 1;
        }

        // Find missing numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            if (arr[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};