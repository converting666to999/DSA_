#include <bits/stdc++.h>
using namespace std;

void func(int ind , vector<int> &ds , vector<int> &arr , vector<vector<int>> &ans)
{
    ans.push_back(ds);

    for(int i = ind; i < arr.size(); i++)
    {   
        if(i > ind && arr[i] == arr[i - 1]) continue; 
        ds.push_back(arr[i]); 
        func(i + 1 , ds , arr , ans); 
        ds.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &arr)
{
    sort(arr.begin() , arr.end());
    int n = arr.size(); 
    vector<vector<int>> ans; 
    vector<int> ds; 

    // fn call
    func(0 , ds , arr , ans); 
    return ans; 
}

int main()
{
    
    return 0;
}