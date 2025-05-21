class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            int a=nums[i];
            int rest=target-a;
            if(mpp.find(rest)!=mpp.end())
                return {i,mpp[rest]};
            mpp[a]=i;
        }
        return {};
    }
};