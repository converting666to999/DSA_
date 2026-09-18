#include <bits/stdc++.h>
using namespace std;

// last occurence
int returnFloor(vector<int> &nums , int target)
{
    int low = 0 , high = nums.size() - 1;
    int ans = -1; 

    while(low <= high)
    {   
        int mid = (low + high) / 2;
        if(nums[mid] <= target)
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

// first occurecne
int returnCeil(vector<int> &nums , int target)
{
    int low = 0 , high = nums.size() - 1;
    int ans = -1; 

    while(low <= high)
    {   
        int mid = (low + high) / 2;
        if(nums[mid] >= target)
        {
            ans = mid;  
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans; 
}

vector<int> firstAndLastOccurence(vector<int> &nums, int target)
{
    vector<int> ans;
    int first = -1, last = -1;

    int low = 0 , high = nums.size() - 1;

    // to find if the target exist in array or not
    while(low <= high)
    {   
        int mid = (low + high) / 2;
        if(nums[mid] == target)
        {   
            // finding the first occurence
            first = returnCeil(nums , target);
            // finding the last occurence
            last = returnFloor(nums , target);
            ans.push_back(first); 
            ans.push_back(last);
            return ans;
        }
        else if(nums[mid] < target) low = mid + 1; 
        else high = mid - 1;
    }

    ans.push_back(first); 
    ans.push_back(last);

    return ans; 
}

int main()
{
    vector<int> a = {5,7,7,8,8,10}; 
    
    // fn call 

    for(auto it : firstAndLastOccurence(a, 9))
    {
        cout << it << " "; 
    }

    return 0;
}