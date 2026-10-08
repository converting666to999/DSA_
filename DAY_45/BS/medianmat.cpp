#include <bits/stdc++.h>
using namespace std;


// brute force 
int findMedian(vector<vector<int>> &arr)
{
    vector<int> temp; 

    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
        {
            temp.push_back(arr[i][j]); 
        }
    }

    sort(temp.begin() , temp.end()); 

    int mid = (0 + (temp.size() - 1)) / 2; 
    return temp[mid];
}

//optimal approach

int upperbound(vector<int> arr , int target)
{
    int low = 0 , high = arr.size() - 1; 
    int ans = arr.size();
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2; 
        if(arr[mid] > target)
        {
            ans = mid; 
            high = mid - 1; 
        }
        else {
            low = mid + 1; 
        }
    }

    return ans; 

}

int blackbox(vector<vector<int>> &arr , int mid)
{   
    int noOfElementsBefore = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        noOfElementsBefore += upperbound(arr[i] , mid); 
    }

    return noOfElementsBefore;
}

int findMedian_op(vector<vector<int>> &arr)
{
    int n = arr.size() , m = arr[0].size(); 
    int low = INT_MAX, high = INT_MIN; 
    int median = (n * m)/2;

    for(int i = 0; i < arr.size(); i++)
        low = min(low , arr[i][0]); 

    for(int i = 0; i < arr.size(); i++)
        high = max(high , arr[i][m - 1]);

    while(low <= high)
    {
        int mid = low + (high - low) / 2; 
        int elementsbefore = blackbox(arr, mid); 

        if(elementsbefore <= median)
            low = mid + 1; 
        else{
            high = mid - 1; 
        }
    }

    return low; 
}

int main()
{
    vector<vector<int>> a = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    }; 

    // fn call 
    cout << findMedian_op(a) << endl; 
    return 0;
}