#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &nums , int t)
{
    int low = 0 , high = nums.size() - 1;

    while( low <= high)
    {
        int mid = (low + high) / 2; 
        if(nums[mid] > t)
            high = mid - 1;
        else if(nums[mid] < t)
            low = mid + 1;
        else 
            return mid;
    }

    return -1;
}

int binarySearch_recursive(vector<int> &nums , int low , int high , int target)
{
    if(low > high) return -1; 

    int mid = (low + high) / 2;  
    
    if(target > nums[mid])
        return binarySearch_recursive(nums, mid + 1, high , target);
    else if(target < nums[mid])
        return binarySearch_recursive(nums , low , mid - 1 , target);
    else return mid;

}

int main()
{
    vector<int> a = {-1,0,3,5,9,12}; 

    // fn call
    cout << binarySearch_recursive(a, 0 , a.size() - 1 , 2) << " \n "; 
    return 0;
}