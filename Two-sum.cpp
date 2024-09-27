class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> map;
       vector<int> res;
       for(int x=0;x<nums.size();x++){
           int findele=target-nums[x];
           if(map.find(findele)!=map.end()){
               return {map[findele],x};
               break;
           }
           map[nums[x]]=x;
           
       }
       return{};
        }};
