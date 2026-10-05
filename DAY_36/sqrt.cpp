#include <bits/stdc++.h>
using namespace std;

int findSqrt(int nums)
{   
    int ans = -1; 
    for(int i = 1; i <= nums; i++)
    {
        if(i * i <= nums)
            ans = i; 
        else 
            break;
    }

    return ans; 
}



int main()
{
    cout << findSqrt(28) << endl; 
    return 0;
}