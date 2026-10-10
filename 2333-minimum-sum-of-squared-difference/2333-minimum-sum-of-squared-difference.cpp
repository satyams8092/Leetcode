class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int k=k1+k2;
        vector<int>diff(1e5+1,0);

        for(int i=0;i<nums1.size();i++){
            int d=abs(nums1[i]-nums2[i]);
            diff[d]++;
        }
        int i=1e5;
        while(diff[i]==0){
            i--;
        }
        for(i;i>0 && k>0;i--){
            int minOps=min(k,diff[i]);
            diff[i]-=minOps;
            diff[i-1]+=minOps;
            k-=minOps;
        }

        long long result=0;
        for(long long i=1;i<=1e5;i++){
            result+=(i*i)*diff[i];
        }

        return result;
    }
};