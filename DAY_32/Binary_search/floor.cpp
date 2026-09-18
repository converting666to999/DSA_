#include <bits/stdc++.h>
using namespace std;

int returnFloor(vector<int> &arr , int target)
{
    int low = 0 , high = arr.size() - 1; 
    int ans = -1;

    while(low <= high)
    {
        int mid = (low + high) / 2; 
        if(arr[mid] <= target)
        {
            ans = mid; 
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> a = {5,7,7,8,8,10}; 
    
    // fn call 
    cout << returnFloor(a , 8) << '\n';
    return 0;
}