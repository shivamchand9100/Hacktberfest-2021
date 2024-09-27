class Solution {
public:
    bool pal(string t,int s,int e)
    {
        while(e>s)
        {
            if(t[e]!=t[s])
                return false;
            e--;
            s++;
        }
        return true;
    }
    
    void help(vector<vector<string>>& res,vector<string>& temp,string s,int index)
    {
        if(index==s.length())
        {
            res.push_back(temp);
            return;
        }
        for(int i=index;i<s.length();i++)
        {
            if(pal(s,index,i))
            {
                temp.push_back(s.substr(index,i-index+1));
                help(res,temp,s,i+1);
                temp.pop_back();
            }
        }
        
    }
    
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        help(res,temp,s,0);
        return res;
    }
};