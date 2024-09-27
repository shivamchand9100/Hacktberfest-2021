class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int[3]>num[9]; // used unordered_map's array of 9 size which denote row/column/box  
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                char c=board[i][j];
                if(c!='.' &&(num[i][c][0]++>0||num[j][c][1]++>0||num[i/3*3+j/3][c][2]++>0))
                {
                    return false;
                }
            }
        }
        return true;
    }
}; 
