class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        
        if(n <= 1)
            return nums[0];
        
        int p=0, q=0;
        
        for (int i=0;i<n;i++)
        {
            int temp = q;
            q = max(p + nums[i], q);
            p = temp;
        }
        return q;
    }
};
//It's nicely done.
