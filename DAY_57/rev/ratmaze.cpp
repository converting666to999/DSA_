#include <bits/stdc++.h>
using namespace std;

class Solution {

private: 

    void solve(int i , int j , int n , string str , vector<int> &di , vector<int> &dj, vector<vector<int>> &maze , vector<string> &ans , vector<vector<int>> &mat)
    {
        if(i == n - 1 && j == n - 1)
        {
            ans.push_back(str); 
            return;
        }

        // recursion
        string dir = "DLRU"; 
        for(int ind = 0; ind < 4; ind++)
        {
            int nxti = i + di[ind]; 
            int nxtj = j + dj[ind];

            if(nxti >= 0 && nxtj >= 0 && nxti < n && nxtj < n && !mat[nxti][nxtj] && maze[nxti][nxtj] == 0)
            {
                mat[nxti][nxtj] = 1;
                solve(nxti , nxtj , n , str + dir[ind] , di , dj , maze , ans , mat);
                // backtrack
                mat[nxti][nxtj] = 0; 

            }
        }
    }

public:

    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        int n = maze.size(); 
        string move = ""; 
        vector<string> ans; 
        vector<int> di = {1 , 0 , 0 , -1}; 
        vector<int> dj = {0 , -1 , 1 , 0}; 
        vector<vector<int>> mat(n , vector<int>(n , 0)); 

        // edge cases
        if(maze.size() == 0 || maze[0].size() == 0 || maze[0][0] == 0)
            return ans;

        mat[0][0] = 1;

        if(maze[0][0] == 1)
            solve(0 , 0 , n , move , di , dj , maze , ans , mat);

        return ans;
    }

};