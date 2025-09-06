class Solution {
public:
    int findMin(vector<int>& arr){
        int minVal = arr[0];
        for(int it : arr){
            if(it < minVal){
                minVal = it;
            }
        }
        return minVal;
    }
    
    int findMax(vector<int>& arr){
        int maxVal = arr[0];
        for(int it : arr){
            if(it > maxVal){
                maxVal = it;
            }
        }
        return maxVal;
    }
    
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
        
        int low = findMin(bloomDay);
        int high = findMax(bloomDay);
        
        while(low<=high){
            int mid=low+(high-low)/2;
            int count=countBouquets(bloomDay,mid,k);
            if(count>=m){
                high=mid-1;   
            } else{
                low=mid+1;
            }
        }
        
        return low;
    }
};