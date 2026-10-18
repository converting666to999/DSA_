#include <bits/stdc++.h>
using namespace std;

void func(int ind , int t , int k , vector<int> &ds , vector<vector<int>> &ans)
{

    //base case
    if(ds.size() == k)
    {
        if(t == 0)
            ans.push_back(ds); 

        return;
    } 

    for(int i = ind;  i <= 9; i++)
    {

        // pick
        if( i <= t)
        {
            ds.push_back(i); 
            func(i + 1 , t - i , k , ds , ans);
            ds.pop_back();
        }
        else continue;
    }
}

vector<vector<int>> combinationSum3(int k, int n) {

    vector<vector<int>> ans; 
    vector<int> ds; 

    //fn call
    func(1 , n , k , ds , ans); 
    return ans;

    
}

int main()
{
    
    return 0;
}