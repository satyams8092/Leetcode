class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=-1;
        for(int it:piles){
            maxi=max(it,maxi);
        }
        int low=1;
        int high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(timeReq(piles,mid)<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
    long long timeReq(vector<int>& piles,int m){
        long long timeReq=0;
        for(int it:piles){
            timeReq += (it + m - 1) / m;;
        }
        return timeReq;
    }
};