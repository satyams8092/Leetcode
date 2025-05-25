class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int posIn=0;
        int negIn=1;
        vector<int>result(n);
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                result[negIn]=nums[i];
                negIn+=2;
            }
            else if(nums[i]>0){
                result[posIn]=nums[i];
                posIn+=2;
            }
        }    
        return result;
    }
};