#include <bits/stdc++.h>
using namespace std;

int kMissingElement(vector<int> &nums , int k)
{
    int low = 0 , high = nums.size() - 1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2; 
        int missing = nums[mid] - (mid + 1); 

        if(missing < k ) 
            low = mid + 1; 
        else high = mid - 1;
    }

    return low + k; 
}

int main()
{
    vector<int> a = {2,3,4,7,11}; 

    // fn call
    cout << kMissingElement(a , 5) << '\n';
    return 0;
}