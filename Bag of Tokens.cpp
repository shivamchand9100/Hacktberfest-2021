class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int j = n - 1, i= 0;
        int score = 0, res = 0;
        while(i < n )
        {
            if(tokens[i] <= power)
            {
                score++;
                res = max(res,score);
                power -= tokens[i];
                i++;
            }
            else if( tokens[i] > power && score >0)
            {
                score--;
                power += tokens[j];
                j--;
            }
            else
            {
                break;
            }
        }
        return res;
    }
};
