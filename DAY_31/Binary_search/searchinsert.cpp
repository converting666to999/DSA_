#include <bits/stdc++.h>
using namespace std;

int searchinsert(vector<int> &nums , int target)
{
    int low = 0 , high = nums.size() - 1; 
    // int ans = 0; 

    while(low <= high)
    {   
        int mid = (low + high) / 2; 
        if(target > nums[mid])
        {
            low = mid + 1; 
        }
        else if(target < nums[mid])
        {
            high = mid - 1; 
        }
        else{
             return mid;
        }
    }
 
    return low;

}

int main()
{
    vector<int> a = {1,3,5,6}; 
    
    // fn call
    cout << searchinsert(a, 2)<< '\n';
    return 0;
}