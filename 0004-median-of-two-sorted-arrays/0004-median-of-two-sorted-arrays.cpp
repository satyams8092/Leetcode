class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
        vector<int>temp;
        while(i<n&&j<m){
            if(nums1[i]<nums2[j]){
                temp.push_back(nums1[i]);
                i++;
            }else{
                temp.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            temp.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            temp.push_back(nums2[j]);
            j++;
        }
        int q=temp.size();
        double ans;
        if(q%2==0){
            int a=(q-1)/2;
            int b=a+1;
            ans=(temp[a]+temp[b])/2.0;
        }else{
            ans=temp[q/2];
        }
        return ans;
    }
};