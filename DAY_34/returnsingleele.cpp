#include <bits/stdc++.h>
using namespace std;

int returnsingleElement(vector<int> &nums)
{   
    int n = nums.size();
    int low = 1 , high = nums.size() - 2;

    // egde cases
    if(nums.size() == 1) 
        return nums[0]; 
    
    if(nums[0] != nums[1])
        return nums[0]; 
    if(nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            return mid;
        
        if(mid % 2 == 1 && nums[mid] == nums[mid - 1])
            low = mid + 1; 
        else if(mid % 2 == 0 && nums[mid] == nums[mid + 1])
            low = mid + 1;
        else 
            high = mid - 1;

    }
    
    return -1;
}

int main()
{
    vector<int> a = {1,1,2,3,3,4,4,8,8}; 
    
    // fn call
    cout << returnsingleElement(a) << endl;

    return 0;
}