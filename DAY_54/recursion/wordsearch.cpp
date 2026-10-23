#include <bits/stdc++.h>
using namespace std;

int m , n;

bool dfs(int ind ,int i , int j , vector<vector<char>> &board, string word)
{   
    // base case 
    if(ind >= word.size())
        return true;

    // out of bound case 
    if(i < 0 || j < 0 || i >= m || j >= n)
        return false; 
    // invalid case 
    if(board[i][j] != word[ind])
        return false;
    // alr visited
    if(board[i][j] == '$')
        return false;

    char temp = board[i][j]; 
    board[i][j] = '$'; 

    // dfs calls
    if( dfs(ind + 1, i - 1 , j , board , word) 
    || dfs(ind + 1, i + 1 , j , board , word)
    || dfs(ind + 1, i , j - 1, board , word)
    || dfs(ind + 1, i , j + 1, board , word))
        return true; 

    // backtracking
    board[i][j] == temp; 
    return false;
}

bool exist(vector<vector<char>> board, string word)
{
    m = board.size(); 
    n = board[1].size();

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == word[0])
            {
                bool found = dfs(0 , i , j , board , word);
                if(found)
                    return true;

            }
        }
    }

    return false;
}

int main()
{
    
    return 0;
}