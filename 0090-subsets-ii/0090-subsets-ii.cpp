class Solution {
public:
    void findSubset(int idx,vector<int>& nums, vector<int>& ds,vector<vector<int>>& result){
        if(idx==nums.size()){
            result.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        findSubset(idx+1,nums,ds,result);
        ds.pop_back();

        while(idx+1 < nums.size() && nums[idx] == nums[idx+1]) idx++;
        findSubset(idx+1,nums,ds,result);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> ds;
        findSubset(0,nums,ds,result);
        return result;
    }
};