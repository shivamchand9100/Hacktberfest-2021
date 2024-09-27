class Solution
{
public:
    bool isValid(vector<vector<char>> &board, char num, int r, int c)
    {
        // check rows and cols
        for(int i = 0; i < 9; i++)
        {
            if((board[r][i] == num) || (board[i][c] == num))
            {
                return false;
            }
        }
        int sub_row = (r - (r % 3));  // top row of this sub-grid
        int sub_col = (c - (c % 3));  // left col of this sub-grid
        // check sub-grids
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[sub_row + i][sub_col + j] == num)
                {
                    return false;
                }
            }
        }
        // no issues found
        return true;
    }
    
    bool solve(vector<vector<char>> &board, int idx)
    {
        // if all nums filled
        if(idx == 81)
        {
            return true;
        }
        int r = (idx / 9);  // current row
        int c = (idx % 9);  // current column
        // if num already here (given to us)
        if(board[r][c] != '.')
        {
            return solve(board, (idx + 1));
        }
        // '.' found
        // try all values 1-9
        for(int i = 1; i <= 9; i++)
        {
            char num = (i + '0');  // current num to try (as a char)
            // if the board would still be valid after inserting this
            if(isValid(board, num, r, c))
            {
                // set value
                board[r][c] = num;
                // keep trying to solve with the next index
                if(solve(board, (idx + 1)))
                {
                    return true;
                }
            }
            // if board is invalid or can't be solved, try again with another num
        }
        // no nums 1-9 work, reset to '.' and backtrack
        board[r][c] = '.';
        return false;
    }
    
    void solveSudoku(vector<vector<char>> &board) 
    {
        solve(board, 0);
    }
};
