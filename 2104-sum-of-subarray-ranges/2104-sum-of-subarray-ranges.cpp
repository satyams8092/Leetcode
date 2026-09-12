class Solution {
public:
    // sum of subarray maximums
    long long sumSubarrayMax(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> left(n), right(n);
        long long sum = 0;

        // previous greater element
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            left[i] = st.empty() ? i+1 : i-st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // next greater element
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            right[i] = st.empty() ? n-i : st.top()-i;
            st.push(i);
        }

        for(int i = 0; i < n; i++)
            sum += (long long)nums[i] * left[i] * right[i];

        return sum;
    }

    // sum of subarray minimums
    long long sumSubarrayMin(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> left(n), right(n);
        long long sum = 0;

        // previous smaller element
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            left[i] = st.empty() ? i+1 : i-st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // next smaller element
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            right[i] = st.empty() ? n-i : st.top()-i;
            st.push(i);
        }

        for(int i = 0; i < n; i++)
            sum += (long long)nums[i] * left[i] * right[i];

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums) - sumSubarrayMin(nums);  // ✅
    }
};