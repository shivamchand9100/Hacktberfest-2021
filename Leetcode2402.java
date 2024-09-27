class Solution {
    public int mostFrequentEven(int[] nums) {
        HashMap<Integer,Integer> map = new HashMap();
        int max = Integer.MIN_VALUE;
        int maxVal = -1;
        for(int c : nums){
            if(c%2==0) {
                map.put(c,map.getOrDefault(c,0)+1);
                 if(map.get(c)>=max){
                     
                      if(map.get(c) == max) {
                          if(maxVal > c) {
                              maxVal = c;
                              continue;
                          }else continue;
                      }
                     
                      max = map.get(c);
                      maxVal = c;
                 }
            }
        }
        return maxVal;
    }
}