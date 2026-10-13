#include <bits/stdc++.h>
using namespace std;

//to find both subsequence
void fnc(int ind , vector<int> &arr , vector<int> &temp , vector<vector<int>> &ans, int sum , int k)
{
    // base case 
    if(ind >= arr.size())
    {
            
        if(sum == k)
        {
            ans.push_back(temp);
        }
        return;
   
    }

    temp.push_back(arr[ind]);
    sum += arr[ind];
    // take
    fnc(ind + 1, arr , temp , ans, sum  + arr[ind], k);
    temp.pop_back();
    sum -= arr[ind]; 
    // not take 
    fnc(ind + 1 , arr , temp , ans , sum  - arr[ind], k);

  

}

//only to find one subsequence
bool func(vector<int> &arr , int k , int sum , vector<int> temp , int ind)
{
    // base case 
    if(ind >= arr.size())
    {
        if(sum == k)
        return true;
        else return false; 
    }
    
    temp.push_back(arr[ind]);
    sum += arr[ind]; 
    
    if(func(arr , k , sum, temp , ind + 1) == true)
        return true; 
        
    temp.pop_back(); 
    sum -= arr[ind]; 
    
    if(func(arr , k , sum , temp , ind + 1) == true)
        return true; 
        
    return false;
}

int countOfsubse(int ind , int k , int sum , vector<int> arr)
{
    // base case 
    if(ind == arr.size())
    {
        if(sum == k)
            return 1;
        else return 0;
    }

    sum += arr[ind]; 

    int x = countOfsubse(ind + 1 , k , sum , arr);
    
    sum -= arr[ind];
    
    int y = countOfsubse(ind + 1 , k , sum , arr);

    return x + y; 
}


void subsequences(vector<int> &arr , int k)
{   
    int sum = 0; 
    vector<int> temp; 
    vector<vector<int>> ans; 

    fnc(0 , arr , temp , ans , sum , k);

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j];

        cout << endl; 
    }
    
}

int main()
{
    vector<int> a = {1 , 2 , 1};

    //fn call 
    subsequences(a , 2);
    return 0;
}