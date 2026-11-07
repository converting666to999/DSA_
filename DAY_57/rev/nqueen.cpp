#include <bits/stdc++.h>
using namespace std;

class Solution {

private: 
    void solve(int col , int n , vector<string> &board ,vector<int> &left , vector<int> &upperD , vector<int> &lowerD , vector<vector<string>> &ans)
    {
        if(col == n)
        {
            ans.push_back(board); 
            return;
        }

        for(int row = 0; row < n; row++)
        {
            if(left[row] == 0 && lowerD[row + col] == 0 && upperD[(n - 1) + (col - row)] == 0 && board[row][col] == '.' && board[row][col] == '.')
            {
                board[row][col] = 'Q';
                left[row] = 1;
                lowerD[row + col] = 1; 
                upperD[(n - 1) + (col - row)] = 1;
                solve(col + 1 , n , board , left , upperD , lowerD , ans); 
                board[row][col] = '.';
                // backtrack
                left[row] = 0;
                lowerD[row + col] = 0; 
                upperD[(n - 1) + (col - row)] = 0;            
            }
        }
    }

public:

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans; 
        vector<string> board(n); 
        string s(n , '.');

        for(int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        // left , upperD , lowerD 
        vector<int> left(n , 0) , upperD(2*n - 1 , 0) , lowerD(2*n - 1 , 0);
        solve(0 , n , board , left , upperD , lowerD , ans);
        return ans;
    }

};