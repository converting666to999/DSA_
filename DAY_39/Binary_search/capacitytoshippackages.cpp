#include <bits/stdc++.h>
using namespace std;

bool func(vector<int> &nums , int cap, int days)
{
    int reqday = 1 , load = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        if( load + nums[i] > cap)
        {
            reqday += 1; 
            load = nums[i];
        }
        else{
            load += nums[i];
        }
    }
    if(reqday == days) return true; 
    return false;
}

int minWeight_brute(vector<int> &nums , int days)
{   
    int maxi = INT_MIN;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        maxi = max(maxi , nums[i]); 
        sum += nums[i];
    }

    for(int i = maxi; i <= sum; i++)
    {
        if(func(nums, i , days) == true)
            return i;
    }

    return -1; 
}

int reqdays(vector<int> &weights , int cap)
{
    int day = 1 , load = 0; 

    for(int i = 0; i < weights.size(); i++)
    {
        if(load + weights[i] > cap)
        {
            day += 1; 
            load = weights[i];
        }
        else{
            load = load + weights[i];
        }
    }

    return day; 
}

int minWeight(vector<int> &weights , int days)
{
    int maxi = INT_MIN;
    int sum = 0;
    for(int i = 0; i < weights.size(); i++)
    {
        maxi = max(maxi , weights[i]); 
        sum += weights[i];
    }

    int low = maxi , high = sum; 

    while(low <= high)
    {
        int mid = low + (high - low) / 2; 
        if(reqdays(weights , mid) <= days)
            high = mid - 1;
        else{
            low = mid + 1;
        }
    }

    return low; 
}

int main()
{
    vector<int> a = {3,2,2,4,1,4};

    // fn call
    cout << minWeight(a , 3) << endl;


    return 0;
}