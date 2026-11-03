class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        
        int maxE = nums[0];
        for(int i=1;i<n;i++){
            maxE=max(maxE,nums[i]);
        }

        int moves=0;
        for(int i=0;i<n;i++){
            moves+=maxE-nums[i];
        }

        return moves;
    }
};