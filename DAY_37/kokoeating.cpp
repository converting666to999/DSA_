#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &nums , int mid)
{
    int ans = 0; 
    for(int i = 0; i < nums.size(); i++)
    {
        ans = ans + ceil(double(nums[i]) / double(mid)); 
    }

    return ans;
}

int returnK(vector<int> &piles , int h)
{
    int low = 1 , high = *max_element(piles.begin() , piles.end());

    while(low <= high)
    {
        int mid = low + (high - low) / 2; 

        if(func(piles , mid) <= h)
            high = mid - 1; 
        else low = mid + 1;
        
    }
    return low;
}

int main()
{
    vector<int> a = {30,11,23,4,20}; 

    // fn call 
    cout << returnK(a, 5) << endl;
    return 0;
}