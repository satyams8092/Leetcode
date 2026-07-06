class Solution {
public:
    void findCombinations(int idx, int target, vector<int>& arr, 
                          vector<int>& ds, vector<vector<int>>& result){
        if(target == 0){
            result.push_back(ds);
            return;
        }
        for(int i = idx; i < arr.size(); i++){
            if(arr[i] > target) break;             // ✅ pruning — no point going further
            if(i > idx && arr[i] == arr[i-1]) continue;  // ✅ skip duplicates
            ds.push_back(arr[i]);
            findCombinations(i+1, target-arr[i], arr, ds, result);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> result;
        findCombinations(0, target, candidates, ds, result);
        return result;
    }
};