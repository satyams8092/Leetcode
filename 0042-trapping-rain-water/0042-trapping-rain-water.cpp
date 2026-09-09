class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> prefixM(n);
        vector<int> suffixM(n);

        prefixM[0]=height[0];
        for(int i=1;i<n;i++){
            prefixM[i]=max(prefixM[i-1],height[i]);
        }

        suffixM[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suffixM[i]=max(suffixM[i+1],height[i]);
        }

        int total=0;
        for(int i=0;i<n;i++){
            int leftMax=prefixM[i];
            int rightMax=suffixM[i];
            if(height[i]<leftMax && height[i]<rightMax){
                total+=min(leftMax,rightMax)-height[i];
            }
        }
        return total;
    }
};