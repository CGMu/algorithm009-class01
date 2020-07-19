class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size=nums.size();
        if(size<1) return 0;
        vector<int> dp(size, 1);
        for(int i=1;i<size;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]) dp[i]=max(dp[i], dp[j]+1);
            }
        }
        auto max_pos=max_element(dp.begin(), dp.end());
        return *max_pos;
    }
};