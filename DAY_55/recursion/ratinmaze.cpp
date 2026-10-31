#include <bits/stdc++.h>
using namespace std;

class Solution {

private: 
    void solve(int i , int j , int n , string move , vector<vector<int>> &vis , vector<vector<int>> &maze , vector<int> &di , vector<int> &dj , vector<string> &ans)
    {
        // base case 
        if(i == n-1 && j == n-1)
        {
            ans.push_back(move); 
            return; 
        }

        string dir = "DLRU"; 
        for(int ind = 0; ind < 4; ind++)
        {
            int nxti = i + di[ind]; 
            int nxtj = j + dj[ind]; 

            // checking out of bound condition
            // !vis is the pos is not been visited
            // and if next pos is traversal or not
            if(nxti >= 0 && nxtj >= 0 && nxti < n && nxtj < n && !vis[nxti][nxtj] && maze[nxti][nxtj] == 1)
            {
                vis[nxti][nxtj] = 1; 
                solve(nxti , nxtj , n , move + dir[ind] , vis , maze , di , dj , ans);
                // backtrack (undo) 
                vis[nxti][nxtj] = 0;
            }
        }
    }

public:

    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        int n = maze.size(); 
        vector<string> ans; 
        string move = ""; 
        vector<vector<int>> vis(n , vector<int>(n , 0));
        vector<int> di = {1 , 0 , 0 , -1}; 
        vector<int> dj = {0 , -1 , 1  ,0}; 

        // edge cases
        if(maze.size() == 0 || maze[0].size() == 0 || maze[0][0] == 0)
            return ans;

        //marking the starting pos
        vis[0][0] = 1;
        
        if(maze[0][0] == 1)
            solve(0 , 0 , n , move , vis , maze , di , dj , ans);

        return ans;

    }

};
