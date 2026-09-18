#include <bits/stdc++.h>
using namespace std;

// extreme brute force sol
void MergeArray(vector<int> &arr1 , vector<int> &arr2 , int n , int m)
{   
    vector<int> arr3(n + m);
    int left = 0; 
    int right = 0; 
    int index = 0;

    while(left < n && right < m)
    {
        if(arr1[left] <= arr2[right])
        {
            arr3[index] = arr1[left]; 
            left++; 
            index++;
        }
        else{
            arr3[index] = arr2[right]; 
            right++; 
            index++;
        }
    }

    while( left < n)
    {
        arr3[index] = arr1[left]; 
        left++; 
        index++;
    }

    while( right < m)
    {
        arr3[index] = arr2[right]; 
        right++; 
        index++;
    }

    for(int i = 0; i < n + m; i++)
    {
        if(i < n) arr1[i] = arr3[i]; 
        else arr2[i - n] = arr3[i];
    }

    
}

int main()
{
    
    return 0;
}