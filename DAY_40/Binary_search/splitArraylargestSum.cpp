#include <bits/stdc++.h>
using namespace std;

int noOfArray(vector<int> nums, int maxArrayCanHold)
{
    int sum = 0 , arr = 1;

    for(int i = 0; i < nums.size(); i++)
    {
        if(sum + nums[i] > maxArrayCanHold){
            sum = nums[i];
            arr++; 
        }
        else{
            sum += nums[i];
        }
    }

    return arr; 
}

int splitArray(vector<int> &nums , int k)
{
    int low = *max_element(nums.begin() , nums.end()); 
    int high = accumulate(nums.begin() , nums.end() , 0);

    // edge case 
    // if(nums.size() < k) return -1;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2; 

        if(noOfArray(nums, mid) > k)
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
    
    return 0;
}