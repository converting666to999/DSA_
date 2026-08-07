	#include <bits/stdc++.h>
	using namespace std;

	void bubble_sort(int arr[], int n)
	{
		for(int i = n - 1; i >= 1; i--)
		{	
			// optimized for best case TC
			int didSwap = 0;
			for(int j = 0; j <= i-1; j++)
			{
				if(arr[j]>arr[j+1])
				{
					swap(arr[j],arr[j+1]);
					didSwap = 1;
				}
			}
			cout << "run \n";
			if(didSwap == 0) { break; }
		}
	}

	void insertion_sort(int arr[], int n)
	{
		for(int i = 0; i <= n-1; i++)
		{
			int j = i;
			while(j > 0 && arr[j-1] > arr[j])
			{
				swap(arr[j-1],arr[j]);
				j--;
			}
		}
	}
	
	int main()
	{
	
	    int n; 
	    cin >> n; 
	    int arr[n];

	    for(int i = 0; i < n; i++)
	    {
	    	cin >> arr[i]; 
	    }

	    insertion_sort(arr, n); 

	    for(int i = 0; i < n; i++)
	    {
	    	cout << arr[i] << " "; 
	    }
	
	    return 0;
	}