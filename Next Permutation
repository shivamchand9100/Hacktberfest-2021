class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int a;
        int x=nums.size();
        for(int i=x-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                 a=i;
                break;
            }
            
        }
        if(a<0){
            reverse(nums.begin(),nums.end());
        }
        else{
        for(int i=x-1;i>a;i--){
            if(nums[i]>nums[a]){
               swap(nums[i],nums[a]);
                break;
            }
            
        }
        reverse(nums.begin()+a+1,nums.end());
        }
    }
};
