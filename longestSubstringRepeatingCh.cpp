class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if (s.size() == 0) {
            return 0;
        }
        unordered_map<char, int> maps;
        
        int ans = INT_MIN, i = 0, j = 0;
        
        while (j < s.size()) {
            
            maps[s[j]]++;
            
            if (maps[s[j]] > 1) {
                char temp = s[j];
                while (maps[temp] > 1) {
                    maps[s[i]]--;
                    i++;
                }
                j++;
            }
            else {
                ans = max(ans, j-i+1);
                j++;
            }
        }
        
        return ans;
        
    }
};
