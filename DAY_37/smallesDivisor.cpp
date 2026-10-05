#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &nums , int mid)
{   
    int ans = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        ans = ans + ceil(double(nums[i])/double(mid));
    }

    return ans;
}

int smallestDivisor(vector<int> &nums , int limit)
{  
    int low = 1 , high = *max_element(nums.begin() , nums.end()); 

    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(func(nums, mid) <= limit)
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
    vector<int> a = {44,22,33,11,1}; 

    // fn call 
    cout << smallestDivisor(a, 5) << endl; 
    return 0;
}