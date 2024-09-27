class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
          return "1";
        if(n == 2)
          return "11";
          
        string s = "11";
        
        for(int i = 3; i <= n; i++)
         {
             s += '$';
             int l = s.length();
             
             int cnt = 1;
             string temp = "";
             
             for(int j = 1; j < l; j++)
              {
                  if(s[j] != s[j - 1])
                    {
                        temp += cnt + '0';
                        temp += s[j - 1];
                        cnt = 1;
                    }
                   else
                     cnt++;
              }
            s = temp;  
         }
         
        return s;
    }
};
