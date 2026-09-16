class Solution {
public:

    int largestRectangle(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        int maxArea=0;

        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                int ele=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty() ? -1 : st.top();
                maxArea=max(maxArea,arr[ele]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int ele=st.top();
            st.pop();
            int nse=n;
            int pse=st.empty() ? -1 : st.top();
            maxArea=max(maxArea,arr[ele]*(nse-pse-1));
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int> arr(m,0);
        int maxArea=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')
                    arr[j]=0;
                else 
                    arr[j]+=1;
            }
            maxArea=max(maxArea,largestRectangle(arr));
        }
        return maxArea;
    }
};