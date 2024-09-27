class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> charMap;
        for(int i=0;i<s.length();i++)
        {
            charMap[s[i]]++;
        }
        
        priority_queue<pair<int,char>> heap;
        for(auto each: charMap)
        {
            heap.push(make_pair(each.second,each.first));
        }
        
        string ans="";
        pair<int,char> use;
        pair<int,char> block;
        while(!heap.empty())
        {
              use = heap.top();
              heap.pop();
              ans = ans + use.second;
              use.first -= 1;
              if(block.first>0)
                  heap.push(block);
              block = use;
        }
        
        if(block.first!=0)
            return "";
        
        return ans;
    }
};
