#include <bits/stdc++.h>
using namespace std;

//tc O(n)
int largest_Element(vector<int> &arr,int n)
{
    int largest = arr[0]; 
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > largest) largest = arr[i];
    }
    return largest;
} 

// sencond largest
int secondLargest(vector<int>& arr)
{   
    int n = arr.size();
    int largest = arr[0]; 
    int slargest = -1; 

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > largest)
        {
            slargest = largest; 
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > slargest)
        {
            slargest = arr[i];
        }
    }
    return slargest;
}  

//second smallest
int secondSmallest(vector<int>& arr)
{
    int n = arr.size();
    int smallest = arr[0];
    int ssmallest = INT_MAX; 

    for(int i = 1; i < n; i++)
    {
        if(arr[i] < smallest)
        {
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] > smallest && arr[i] < ssmallest)
        {
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

//if array is sorted
bool isSorted(vector<int> &a)
{
    int n = a.size();

    for(int i = 1; i < n; i++)
    {
        if(a[i] >= a[i-1]) { }
        else return false;
    }
    return true;
}

// remove in place duplicate 
// tc = O(n)
// sc = O(1)
int removeDupe(vector<int> &a)
{
    int n = a.size(); 
    int i = {0}; 

    for(int j = 1; j < n; j++)
    {
        if(a[j] != a[i])
        {
            a[i+1] = a[j]; 
            i++;
        }
    }

    return (i+1);
}

//rotate array by 1
void rotateArray(vector<int> &a)
{
    int n = a.size(); 
    int temp = a[0]; 

    for(int i = 1; i < n; i++)
    {
        a[i-1] = a[i];
    }

    a[n-1] = temp;
}

int main()
{

    int n; 
    cin >> n; 

    vector<int> arr(n); 

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i]; 
    }

    rotateArray(arr); 

    for(auto it : arr)
    {
        cout << it << " ";
    }
    

    return 0;
}