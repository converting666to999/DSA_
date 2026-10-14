#include <bits/stdc++.h>
using namespace std;

void func(int i , int target , vector<int> &arr,  vector<int> &current , vector<vector<int>> &ans)
{
    if(i == arr.size())
    {
        if(target == 0)
            ans.push_back(current); 
        return;
    }

    if(arr[i] <= target)
    {
        current.push_back(arr[i]);
        func(i , target - arr[i] , arr , current , ans);
        current.pop_back();
    } 
     
    func(i + 1, target , arr , current ,  ans);  
}

vector<vector<int>> combi(vector<int> &arr , int t)
{
    vector<vector<int>> ans;
    vector<int> current;
    func(0 , t , arr,  current, ans);

    return ans; 
}

int main()
{
    
    return 0;
}