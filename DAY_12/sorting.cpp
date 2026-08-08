#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low ,int mid , int high)
{
	vector<int> temp; 
	int left = low; 
	int right = mid + 1; 

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

//MergeSort
void mergeSort(vector<int> &arr, int low , int high)
{
	if(low >= high) return; 
	int mid = (low + high) / 2; 
	mergeSort(arr,low,mid);
	mergeSort(arr,mid+1,high); 
	merge(arr,low,mid,high);
}

//bubble sort using recursion
void Bubble_Sort(vector<int> &arr, int n)
{
	// base case
	if (n == 1) return;

	for(int i = 0; i <= n - 2; i++)
	{
		if(arr[i] > arr[i+1]) { swap(arr[i],arr[i+1]); }
	}


	Bubble_Sort(arr, n - 1);
}

// insertion sort using recursion
void insertion_sort(vector<int> &arr , int i , int n)
{
	// base case 
	if( i == n) return; 

	int j = i;
	while(j > 0 && arr[j - 1] > arr[j])
	{
		swap(arr[j - 1],arr[j]);
		j--;
	}

	insertion_sort(arr,i+1,n);
}

int partition(vector<int> &arr , int low , int high)
{
	int pivot = arr[low]; 
	int i = low;
	int j = high; 

	while(i < j)
	{
		while(arr[i] <= pivot && i <= high - 1 )
		{
			i++;
		}

		while(arr[j] > pivot && j >= low + 1)
		{
			j--;
		}

		if(i < j) swap(arr[i],arr[j]);
	}

	swap(arr[low],arr[j]); 
	return j;
}

void Quick_sort(vector<int> &arr, int low, int high)
{
	if(low < high)
	{
		int pIndex = partition(arr,low,high); 
		Quick_sort(arr,low , pIndex - 1); 
		Quick_sort(arr,pIndex + 1, high);
	}
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

	Quick_sort(arr,0,n-1);

	for(auto it : arr)
	{
		cout << it << " ";
	}




    return 0;
}