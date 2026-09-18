#include <bits/stdc++.h>
using namespace std;

// brute
int countInversion(vector<int> &arr)
{
    int cnt = 0; 

    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = i + 1; j < arr.size(); j++)
        {
            if(arr[i] > arr[j])
                cnt += 1;
        }
    }
    return cnt;
}

// optimal solution using merges_sort
int merge(vector<int> &arr, int low , int mid , int high)
{   
    
    int left = low; 
    int right = mid + 1;
    vector<int> temp;
    int cnt = 0;

    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {   
            temp.push_back(arr[left]); 
            left++;
        }
        else{

            temp.push_back(arr[right]); 
            cnt += (mid - left + 1);
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

    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{   
    int cnt = 0;
    if(low >= high) return cnt;

    int mid = (low + high) / 2; 
    cnt += mergeSort(arr, low , mid); 
    cnt += mergeSort(arr, mid+1 , high); 
    cnt += merge(arr, low , mid , high);

    return cnt;
}

int cntInver_Op(vector<int>& arr)
{
    return mergeSort(arr,0,arr.size() - 1); 
}

int main()
{   

    vector<int> a = {2, 4, 1, 3, 5}; 

    cout << cntInver_Op(a) << '\n';
    
    return 0;
}