class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0;
        int cmax=0;
        for(int it:nums){
            if(it==1){
                cmax+=1;
            }
            else{
                if(cmax>max){
                    max=cmax;
                    cmax=0;
                }
                else
                    cmax=0;   
            }
        }
        if(cmax>max) return cmax;
        else return max;
    }
};