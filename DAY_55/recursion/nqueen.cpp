#include <bits/stdc++.h>
using namespace std;

class Solution {

private: 

    bool isSafe(int row , int col , vector<string> &board , int n)
    {
        //checking diagonally
        int duprow = row; 
        int dupcol = col; 

        while(row >= 0 && col >= 0)
        {
            if(board[row][col] == 'Q') return false; 
            row--; 
            col--; 
        }

        row = duprow; 
        col = dupcol; 

        while(col >= 0)
        {
            if(board[row][col] == 'Q') return false; 
            col--; 
        }

        row = duprow; 
        col = dupcol; // just to be safe

        while(row < n && col >= 0)
        {
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string> &board , vector<vector<string>> &ans , int n)
    {
        if(col == board.size())
        {
            ans.push_back(board); 
            return;
        }

        for(int row = 0; row < n; row++)
        {
            if(isSafe(row , col , board , n))
            {
                board[row][col] = 'Q'; 
                solve(col + 1 , board , ans , n); 
                board[row][col] = '.';
            }
        }
    }

    
public:

    vector<vector<string>> Nqueen(int n)
    {   
        vector<vector<string>> ans; 
        vector<string> b(n); 
        string s(n , '.');

        for(int i = 0; i < n; i++)
        {
            b[i] = s; 
        }

        solve(0 , b , ans , n); 
        return ans;
    }
};
