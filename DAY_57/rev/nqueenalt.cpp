#include <bits/stdc++.h>
using namespace std;

class Solution {
        
  public:
    
    void solve(int col , int n , vector<int> &left , 
    vector<int> &upperD , vector<int> &lowerD , vector<vector<int>> &ans , 
    vector<vector<int>> &vis)
    {
        if(col == n)
        {   
            vector<int> temp;
            for(int i = 0; i < vis.size(); i++)
                for(int j = 0; j < vis[0].size(); j++)
                {
                    if(vis[i][j] == 1)
                        temp.push_back(j + 1);
                }
            ans.push_back(temp);
            return; 
        }
        
        for(int row = 0; row < n; ++row)
        {
            if(left[row] == 0 && upperD[(n - 1) + (col - row)] == 0 && 
            lowerD[col + row] == 0)
            {
                vis[col][row] = 1; 
                left[row] = 1; 
                upperD[(n - 1) + (col - row)] = 1; 
                lowerD[col + row] = 1;
                solve(col + 1 , n , left , upperD , lowerD , ans , vis);
                vis[col][row] = 0;
                left[row] = 0; 
                upperD[(n - 1) + (col - row)] = 0; 
                lowerD[col + row] = 0;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        // track to see if visited or not
        vector<vector<int>> vis(n , vector<int>(n , 0));
        vector<int> pos(n , 0);
        
        // is it safe? 
        vector<int> left(n , 0) , upperD(2*n - 1 , 0) , lowerD(2*n - 1 , 0); 
        solve(0 , n , left , upperD , lowerD , ans , vis);
        
        return ans;
    }
};