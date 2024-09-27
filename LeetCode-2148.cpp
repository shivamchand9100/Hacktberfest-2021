class Solution {
public:
    int countElements(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        sort(nums.begin(),nums.end());
        map<int , int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int cnt=0;
        if(mp.size()==1)
            return 0;
        for(auto itr:mp) {
            cnt = cnt+ itr.second;
        }
        return (cnt-(mp[nums[0]]+mp[nums[nums.size()-1]]));
    }
};
