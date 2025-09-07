class Solution {
public:
    int calDays(vector<int>&nums,int mid){
        int day=1;
        int load=0;
        for(auto it:nums){
            if(load+it>mid){
                day++;
                load=it;
            }else{
                load+=it;
            }
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        long long high=accumulate(weights.begin(),weights.end(),0LL);
        while(low<=high){
            int mid=low+(high-low)/2;
            int rqDays=calDays(weights,mid);
            if(rqDays<=days){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};