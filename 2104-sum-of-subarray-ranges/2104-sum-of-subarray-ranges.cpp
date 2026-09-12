class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int largest=nums[i];
            int smallest=nums[i];
            for(int j=i;j<n;j++){
                largest=max(nums[j],largest);
                smallest=min(nums[j],smallest);
                sum+=(largest-smallest);
            }
        }
        return sum;
    }
};