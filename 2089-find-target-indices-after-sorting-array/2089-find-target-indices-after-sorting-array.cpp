class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n=nums.size();
        int prev=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]<target) prev++;
            if(nums[i]==target) cnt++;
        }
        vector<int> res;
        for(int i=0;i<cnt;i++){
            res.push_back(prev++);
        }
        return res;
    }
};