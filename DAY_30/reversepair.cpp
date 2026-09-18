#include <bits/stdc++.h>
using namespace std;

// fn that wiil do the actual lifting



void merge(vector<int> &arr , int low , int mid , int high)
{
    int left = low; 
    int right = mid + 1; 
    vector<int> temp;

    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]); 
            left++;
        }
        else{

            temp.push_back(arr[right]); 
            right++;
        }
    }

    while(left <= mid)
    {
        temp.push_back(arr[left]); 
        left++;
    }

    while(right <= high)
    {
        temp.push_back(arr[right]); 
        right++;
    }

    for(int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low]; 
    }
}

int calcPairs(vector<int> &arr, int low , int mid , int high)
{
    int cnt = 0;
    int right = mid + 1;

    for(int i = low; i <= mid; i++)
    {
        while(right <= high && arr[i] > (2 * arr[right]))
            right++; 
        
        cnt += right - (mid + 1);
    }

    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{   
    int cnt = 0;
    if(low >= high) return cnt; 

    int mid = (low + high) / 2; 
    cnt += mergeSort(arr, low , mid); 
    cnt += mergeSort(arr, mid+1, high); 
    cnt += calcPairs(arr, low , mid , high);
    merge(arr , low , mid , high);

    return 1;
}



int reversePairs(vector<int> &nums)
{
    return mergeSort(nums, 0 , nums.size() - 1);  
}

int main()
{
    vector<int> a = {2,4,3,5,1}; 

    // fn call 
    cout << reversePairs(a) << '\n'; 

    return 0;
}