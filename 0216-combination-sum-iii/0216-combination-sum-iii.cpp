class Solution {
public:
    void findCombination(vector<vector<int>>& result,vector<int>& ds,int k, int n,int idx){
        if(ds.size()==k){
            if(n==0){
                result.push_back(ds);
            }
            return;
        }
        if(idx<=9){
            if(n>=0){
                ds.push_back(idx);
                findCombination(result,ds,k,n-idx,idx+1);
                ds.pop_back();
            }
            findCombination(result,ds,k,n,idx+1);
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> ds;
        int idx=1;
        findCombination(result,ds,k,n,idx);
        return result;
    }
};