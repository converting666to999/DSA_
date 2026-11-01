#include <bits/stdc++.h>
using namespace std;

class Solution {

private:

    bool isValid(char c , vector<vector<char>> &board , int i , int j)
    {
        for(int ind = 0; ind < board.size(); ind++)
        {
            // checking rows 
            if(board[i][ind] == c) return false; 
            // checking col 
            if(board[ind][j] == c) return false; 

            // checking 3x3 grid
            int row = (3 * (i / 3)) + (ind / 3); 
            int col = (3 * (j / 3)) + (ind % 3);

            if(board[row][col] == c) return false; 
        }
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == '.')
                {
                    for(char c = '1'; c <= '9'; c++)
                    {   
                        // black box for now
                        if(isValid(c , board , i , j))
                        {
                            board[i][j] = c; 
                            if(solve(board) == true)
                                return true;
                            else 
                                board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }

        return true;
    }

public:
   void solveSudoku(vector<vector<char>> &board)
   {
        solve(board);
   }
};
