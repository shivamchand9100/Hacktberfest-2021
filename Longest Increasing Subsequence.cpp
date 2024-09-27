class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            int temp = dp.size();
            if(nums[i] > dp[temp-1])
                dp.push_back(nums[i]);
            else
            {
                int p = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                if(p < temp)
                    dp[p] = nums[i];
            }
        }
        return dp.size();
    }
};
