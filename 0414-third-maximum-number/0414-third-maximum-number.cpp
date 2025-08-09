class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
        {
            return *max_element(nums.begin(),nums.end());
        }    
        sort(nums.begin(),nums.end(),greater <int>());
        unordered_set <int> sets;
        for(int num:nums)
        {
            sets.insert(num);
            if(sets.size()==3)
            {
                return num;  // Third distinct maximum found
            }
        }
        return *max_element(nums.begin(),nums.end());  // Less than 3 distinct elements
    }
};