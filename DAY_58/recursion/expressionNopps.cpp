#include <bits/stdc++.h>
using namespace std;


class Solution {

private: 
    void solve(string num , int target , vector<string> &ans , int i ,const string &path , long long eval , long long residual)
    {
        // base case
        if(i == num.size())
        {
            if(eval == target)
            {
                ans.push_back(path); 
                return; 
            }
        }

        string currStr; 
        long long resi = 0;

        for(int j = i; j < num.size(); j++)
        {   
            // edge case
            // return marne ka
            if(j > i && num[i] == '0') return;

            currStr += num[j];
            // add -0 char to convert it into decimal
            resi = resi * 10 + num[j] - '0';
           
            if(i == 0)
            {
                solve(num , target , ans , j + 1 , path + currStr, resi, resi); 
            }
            else{
                solve(num , target , ans , j + 1 , path + "+" + currStr , eval + resi , resi); 
                solve(num , target , ans , j + 1 , path + "-" + currStr , eval - resi , -resi); 
                solve(num , target , ans , j + 1 , path + "*" + currStr , eval - residual + residual * resi , residual * resi);
            }
        }
    }

public:

    vector<string> addOperators(string num , int target)
    {   
        vector<string> ans;
        solve(num , target , ans, 0 , "" , 0 , 0); 
        return ans;
    }


};