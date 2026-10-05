#include <bits/stdc++.h>
using namespace std;

bool canWeplace(vector<int> nums , int dist , int k)
{
    int cntCow = 1 , lastCow = nums[0];
    for(int i = 0; i < nums.size(); i++)
    {
        if((nums[i] - lastCow) >= dist)
        {
            cntCow++; 
            lastCow = nums[i]; 
        }
    }

    if(cntCow >= k) return true;
    return false; 
}

// linear Search
// int maximizedDistance(vector<int> &nums , int k)
// {
//     sort(nums.begin() , nums.end()); 

//     int min = *min_element(nums.begin() , nums.end()); 
//     int max = *max_element(nums.begin() , nums.end());

//     int high = max - min;
    
//     for(int i = 1; i <= high; i++)
//     {
//         if(canWeplace(nums, i , k) == true)
//             continue; 
//         else{
//             return (i - 1); 
//         }
//     }
    
//     return -1;
// }

//binary search
int maximizedDistance(vector<int> nums , int k)
{   
    sort(nums.begin() , nums.end()); 

    int low = 1 , high = nums[nums.size() - 1] - nums[0]; 

    while(low <= high)
    {   
        int mid = low + (high - low) / 2;
        if(canWeplace(nums , mid , k) == true)
            low = mid + 1; 
        else high = mid - 1;
    }

    return high;
}

int main()
{
    vector<int> a = {1, 2, 4, 8, 9}; 
    
    // fn call 
    cout << maximizedDistance(a , 3) << endl; 
    return 0;
}