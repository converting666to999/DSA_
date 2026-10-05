#include <bits/stdc++.h>
using namespace std;

int noOfStudents(vector<int> &nums , int cap)
{
    long long totalPages = 0;
    int st = 1;

    for(int i = 0; i < nums.size();i++)
    {
        if(totalPages + nums[i] > cap)
        {
            totalPages = nums[i]; 
            st++; 
        }
        else{ 
            totalPages += nums[i];
        }
    }

    return st;
}

int findPages(vector<int> &nums , int m)
{
    int low = *max_element(nums.begin() , nums.end()); 
    int high = accumulate(nums.begin() , nums.end() , 0); 

    // edge case 
    if(nums.size() < m) return -1; 

    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(noOfStudents(nums , mid) > m)
        {
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }

    }

    return low; 
}

int main()
{
    vector<int> a = {12, 34, 67, 90}; 

    // fn call
    cout << findPages(a , 2) << endl; 

    return 0;
}