#include <bits/stdc++.h>
using namespace std;

void recursiveFunc(int ind , int n , vector<int> temp , vector<int> nums,vector<vector<int>> ans)
{
    // base case
    if(ind >= n)
    {
        ans.push_back(temp); 
        return;
    }

    temp.push_back(nums[ind]);
    recursiveFunc(ind+1 , n , temp , nums , ans); 
    temp.pop_back();
    recursiveFunc(ind+1 , n , temp , nums , ans);

}

vector<vector<int>> subsets(vector<int> nums)
{   
    //for picking subsets
    vector<int> temp;

    vector<vector<int>> ans; 
    recursiveFunc(0 , nums.size() , temp  , nums , ans);
    return ans; 
}

int main()
{
    
    return 0;
}