#include <bits/stdc++.h>
using namespace std;

int findPeak(vector<int> &nums)
{   
    int n = nums.size();
    int low = 1 , high = nums.size() - 2; 

    // edge cases
    if(nums[0] > nums[1])
        return 0; 
    if(nums[n - 1] > nums[n - 2])
        return n - 2; 

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;
        if(nums[mid] > nums[mid - 1])
            low = mid + 1;
        else high = mid - 1;
    }
    
    return -1; 
}

int main()
{
    vector<int> a = {1,2,1,3,5,6,4}; 

    // fn call
    cout << findPeak(a) << endl;

    return 0;
}