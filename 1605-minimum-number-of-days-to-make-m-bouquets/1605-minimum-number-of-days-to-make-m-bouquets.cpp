class Solution {
public:
    // Helper function to count bouquets possible on a given day
    int countBouquets(vector<int>& bloomDay, int day, int k) {
        int bouquets = 0;
        int consecutive = 0;
        
        for(int bloom : bloomDay) {
            if(bloom <= day) {  // Flower has bloomed
                consecutive++;
                if(consecutive == k) {  // We can make a bouquet
                    bouquets++;
                    consecutive = 0;  // Reset for next bouquet
                }
            } else {
                consecutive = 0;  // Reset consecutive count
            }
        }
        return bouquets;
    }
    
    // Optimal Approach
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n < (long long)m * k) return -1;  // Prevent overflow
        
        int low = INT_MAX, high = INT_MIN;
        for (int day : bloomDay) {
            low = min(low, day);
            high = max(high, day);
        }
        
        while(low<=high){
            int mid=low+(high-low)/2;
            int count=countBouquets(bloomDay,mid,k);
            if(count=countBouquets(bloomDay,mid,k)>=m){
                high=mid-1;   
            } else{
                low=mid+1;
            }
        } 
        return low;
    }
};