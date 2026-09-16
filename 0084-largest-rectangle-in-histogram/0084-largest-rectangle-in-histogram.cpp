class Solution {
public:
    vector<int> findpse(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        vector<int> pse(n);

        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                st.pop();
            }
            pse[i]=st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int> findnse(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        vector<int> nse(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse=findnse(heights);
        vector<int> pse=findpse(heights);
        
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            maxi=max(maxi,heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }
};