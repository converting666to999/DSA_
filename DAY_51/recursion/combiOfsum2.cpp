#include <bits/stdc++.h>
using namespace std;

void func(int ind , int target , vector<int> &arr , vector<int> &current , vector<vector<int>> &ans)
{
    if(target == 0)
    {
        ans.push_back(current); 
        return; 
    }

    for(int i = ind; i < arr.size(); i++ )
    {
        // not pick
        if(i > ind && arr[i] == arr[i - 1]) continue; 
        if(arr[i] > target) break; 

        // pick
        current.push_back(arr[i]); 
        func(i + 1 , target - arr[i] , arr , current , ans);
        current.pop_back();
    }
}

vector<vector<int>> combiOfsum(vector<int> &arr , int target)
{
    sort(arr.begin() , arr.end()); 
    vector<vector<int>> ans; 
    vector<int> current; 

    // fn call 
    func(0 , target , arr , current , ans); 
    return ans; 
}

int main()
{
    
    return 0;
}