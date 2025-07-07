class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int el1=INT_MIN;
        int el2=INT_MIN;
        map<int,int>mpp;
        for(auto it:nums){
            if(cnt1==0 && el2!=it){
                cnt1=1;
                el1=it;
            }
            else if(cnt2==0 && el1!=it){
                cnt2=1;
                el2=it;
            }
            else if(it==el1) cnt1++;
            else if(it==el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=cnt2=0;
        for(auto it:nums){
            if(el1==it) cnt1++;
            else if(el2==it) cnt2++;
        }
        vector<int>ans;
        int mini=(int)(nums.size()/3)+1;
        if(cnt1>=mini) ans.push_back(el1);
        if(cnt2>=mini) ans.push_back(el2);
        return ans;
    }
};