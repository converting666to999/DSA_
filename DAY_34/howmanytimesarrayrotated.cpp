#include <bits/stdc++.h>
using namespace std;

int kRotation(vector<int> &nums)
{
    int low = 0 , high = nums.size() - 1; 
    int ans = INT_MAX;
    int k = 0; 

    while(low <= high)
    {   
        int mid = low + (high - low) / 2; 

        if(nums[low] <= nums[high])
        {
            if(nums[low] < ans)
            {
                k = low; 
                ans = nums[low];
            }
            break;
        }

        if(nums[low] <= nums[mid])
        {
            if(nums[low] < ans)
            {
                k = low; 
                ans = nums[low];
            }
            low = mid + 1;
        }
        else{
            if(nums[mid] < ans)
            {
                k = mid; 
                ans = nums[mid];
            }
            high = mid - 1;
        }
    }

    return k;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5}; 

    //  fn call 
    cout << kRotation(a) << endl;
    return 0;
}