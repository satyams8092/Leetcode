class Solution {
    vector<int> generateRow(int row){
        long long result=1;
        vector<int>ans;
        ans.push_back(1);
        for(int col=1;col<row;col++){
            result=result*(row-col);
            result=result/col;
            ans.push_back(result);
        }
        return ans;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};