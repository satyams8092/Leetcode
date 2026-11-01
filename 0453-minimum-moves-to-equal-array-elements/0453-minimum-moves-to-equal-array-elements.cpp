class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        
        int mini=nums[0];
        for(int i=1;i<n;i++){
            mini=min(nums[i],mini);
        }

        int moves=0;
        for(int i=0;i<n;i++){
            moves+=nums[i]-mini;
        }  

        return moves;
    }
};