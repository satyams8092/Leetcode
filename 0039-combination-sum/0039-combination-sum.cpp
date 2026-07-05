class Solution {
public:
    vector<vector<int>> result;

    void findCombinations(int idx,int target,vector<int>& arr, vector<int>& ds){
        if(idx==arr.size()){
            if(target==0){
                result.push_back(ds);
            }
            return;
        }
        //if we pick the ele at the idx
        if(arr[idx]<=target){
            ds.push_back(arr[idx]);
            findCombinations(idx,target-arr[idx],arr,ds);
            ds.pop_back();
        }
        findCombinations(idx+1,target,arr,ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        findCombinations(0,target,candidates,ds);
        return result;
    }
};