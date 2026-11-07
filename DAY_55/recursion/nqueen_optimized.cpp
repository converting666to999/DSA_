#include <bits/stdc++.h>
using namespace std;

class Solution {

private: 
    void solve(int col , int n , vector<string> &board , vector<vector<string>> &ans , vector<int> left , vector<int> upperD , vector<int> lowerD)
    {
        // base case 
        if(col == board.size())
        {
            ans.push_back(board); 
            return;
        }

        for(int row = 0; row < n; row++)
        {
            if(left[row] == 0 && upperD[n - 1 + (col - row)] == 0 && lowerD[row + col] == 0)
            {
                board[row][col] = 'Q';
                left[row] = 1; 
                upperD[n - 1 + (col - row)] = 1; 
                lowerD[row + col] = 1; 
                solve(col + 1 , n , board , ans , left , upperD , lowerD); 
                // backtracking(undo everything)
                board[row][col] = '.'; 
                left[row] = 0; 
                upperD[n - 1 + (col - row)] = 0; 
                lowerD[row + col] = 0; 

            }
        }

        
    }

public:
   vector<vector<string>> solveNQueens(int n)
   {
        vector<vector<string>> ans;
        vector<string> board(n);
        // making 2d grind of string 
        string s(n , '.'); 

        for(int i = 0; i < n; i++)
        {
            board[i] = s; 
        }

        // making hashMap for checking
        // left 
        // upperdiagonal
        // lowerdiagonal
        vector<int> left(n - 1 , 0) , upperD(2 * n - 1 , 0) , lowerD(2 * n - 1 , 0); 
        //rec fn
        solve(0 , n , board , ans , left , upperD , lowerD); 
        return ans;
   }
};
