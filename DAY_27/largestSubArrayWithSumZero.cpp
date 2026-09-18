#include <bits/stdc++.h>
using namespace std;

int largestSubArray_Zero(vector<int> &arr)
{
    int n = arr.size(); 
    int maxi = INT_MIN; 
    int currMaxi;
    int sum = 0;
    unordered_map<int , int> Prefix;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum == 0)
        {
            maxi = i + 1;
        }
        else if(Prefix.find(sum) == Prefix.end())
        {
            Prefix[sum] = i;
        }

        if(Prefix.find(sum) != Prefix.end())
        {
            currMaxi = i - Prefix[sum];
            maxi = max(maxi , currMaxi);
        }
    }

    return maxi;
}

int main()
{
    vector<int> a = {1, 0, -4, 3, 1, 0}; 

    cout << largestSubArray_Zero(a) << '\n'; 
    return 0;
}