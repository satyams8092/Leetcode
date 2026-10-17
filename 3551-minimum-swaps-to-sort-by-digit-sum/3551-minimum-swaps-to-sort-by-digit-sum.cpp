class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();

        vector<int> sortedNums(nums);

        auto lambda= [&](int num1,int num2){
            int digitSum1=digitSum(num1);
            int digitSum2=digitSum(num2);

            if(digitSum1 != digitSum2){
                return digitSum1<digitSum2;
            }
            return num1<num2;
        };

        sort(begin(sortedNums),end(sortedNums),lambda);

        map<int,int> valToidx;
        for(int i=0;i<n;i++){
            valToidx[nums[i]]=i;
        }

        int swap=0;
        for(int i=0;i<n;i++){
            int expectedVal=sortedNums[i];
            int currVal=nums[i];

            if(expectedVal==currVal) continue;

            int idx=valToidx[expectedVal];

            nums[i]=expectedVal;
            nums[idx]=currVal;

            valToidx[currVal]=idx;
            valToidx[expectedVal]=i;

            swap++;
        }

        return swap;
    }

    int digitSum(int num){
        int sum=0;

        while(num>0){
            sum+=num%10;
            num/=10;
        }

        return sum;
    }
};