#include <bits/stdc++.h>
using namespace std;

//brute approach
bool ifPossible(vector<int> &nums , int day , int m , int k)
{   
    int cnt = 0 , tbq = 0;
    for(int i = 0; i < nums.size() - 1; i++)
    {
        if(nums[i] <= day)
            cnt += 1; 
        else{
            tbq += (cnt/k);
            cnt = 0; 
        }
    }
    tbq += (cnt/k);
    if(tbq >= m) return true; 
    return false;
}

int minimumDays_brute(vector<int> &nums , int m , int k)
{   
    int mini = *min_element(nums.begin() , nums.end());
    int maxi = *max_element(nums.begin(), nums.end()); 

    // edge case
    if(nums.size() < (m * k)) return -1;

    for(int i = mini; i <= maxi; i++)
    {
        if(ifPossible(nums , i , m , k) == true)
            return i;
    }
    return -1;
}

// binary search
int minimumDays(vector<int> &nums , int m , int k)
{
    int low = *min_element(nums.begin() , nums.end()); 
    int high = *max_element(nums.begin() , nums.end());

    // edge case
    if(nums.size() < (m * k)) return -1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(ifPossible(nums, mid , m , k) == true)
        {
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return low;
}


int main()
{
    vector<int> a = {7,7,7,7,12,7,7}; 
    
    // fn call
    // cout << minimumDays(a, 2 , 3) << endl; 
    cout << minimumDays(a, 2 , 3) << endl;
    return 0;
}