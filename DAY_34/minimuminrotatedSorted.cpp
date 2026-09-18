#include <bits/stdc++.h>
using namespace std;

int searchMinimum(vector<int> &nums)
{
    int low = 0 , high = nums.size() - 1;
    int ans = INT_MAX; 

    while(low <= high)
    {
        int mid = (low + high) / 2; 

        if(nums[low] <= nums[mid])
        {
            ans = min(ans , nums[low]); 
            low = mid + 1; 
        }
        else{
            ans = min(ans , nums[mid]); 
            high = mid - 1; 
        }
    }

    return ans;
}

int main()
{
    vector<int> a = {11,13,15,17}; 

    // fn call 
    cout << searchMinimum(a) << endl;

    return 0;
}