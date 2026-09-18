#include <bits/stdc++.h>
using namespace std;

// fucking code mess that ive written 
// will always return 3 or 4
int lowerbound(vector<int> &nums , int target)
{
    int low = 0 , high = nums.size() - 1;
    int ans = nums.size();

    while(low <= high)
    {   
        int mid = (low + high) / 2;
        if(nums[mid] >= target)
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

int main()
{
    vector<int> a = {2, 3, 7, 10, 11, 11, 25}; 

    // fn call
    cout << lowerbound(a, 9) << '\n';

    return 0;
}