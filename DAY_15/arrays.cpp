#include <bits/stdc++.h>
using namespace std;

//q7 brute approach
void moveZeroes(vector<int> &a)
{

	int n = a.size(); 
	// sc O(n) extra space
	vector<int> temp;

	// storing the no negative 0s
	for(int i = 0; i < n; i++)
	{
		if(a[i] != 0)
		{
			temp.push_back(a[i]);
		}
	}

	// replacing the starting value with temp values
	for(int i = 0; i < temp.size(); i++)
	{
		a[i] = temp[i];
	}

	// asigning the remaining value zero
	// tc O(n - x)
	for(int i = temp.size(); i < n; i++)
	{
		a[i] = 0;
	}
}

//optimal approach 
void moveZeroesOP(vector<int> &a)
{
	int n = a.size();
	// if there is no zeros in the array
	// it stays -1  
	int j = -1; 

	// j always starts at 0
	for(int i = 0; i < n; i++)
	{
		if( a[i] == 0) j = i;
		break;
	}

	for(int i = 0; i < n; i++)
	{
		if(a[i] != 0)
		{	
			// could have used swap function
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			j++;
		}
	}
}

// q8
int linearSearch(vector<int> &a, int t)
{	
	int n = a.size();
	for(int i = 0; i < n; i++)
	{
		if(a[i] == t) return i; 

	}
	return -1;
}

// q9 brute force
vector<int> unionOfarrays(vector<int> nums1,vector<int> nums2)
{
	set<int> st; 

	for(int i = 0; i < nums1.size(); i++)
	{
		st.insert(num1[i]);
	}

	for(int i = 0; i < nums2.size(); i++)
	{
		st.insert(num2[i]);
	}

	vector<int> un; 

	for(int i = 0; i < st.size(); i++)
	{
		un.push_back(st[i]);
	}

	return un;
}

// optimal approach
vector<int> unionOfarraysOP(vector<int> nums1, vector<int> nums2)
{
	vector<int> un; 
	int i = 0; 
	int j = 0;
	int n1 = nums1.size(); 
	int n2 = nums2.size(); 

	while(i < n1 && j < n2)
	{
		if(nums1[i] <= nums2[j])
		{
			if(un.size() == 0 || un.back() != nums1[i])
			{
				un.push_back(nums1[i]);
			}
			i++;
		}
		else{

			if(un.size() == 0 || un.back() != nums2[j])
			{
				un.push_back(nums2[j]);
			}
			j++;
		}

	}

	while(j < n2)
	{
		if(un.size() == 0 || un.back() != nums2[j])
			{
				un.push_back(nums2[j]);
			}
			j++;
	}

	while(i < n1)
	{
		if(un.size() == 0 || un.back() != nums1[i])
			{
				un.push_back(nums1[i]);
			}
			i++;
	}

	return un;
}

int main()
{
	int m;
	cin >> m;

	int n = arr.size();

	for(int i = 0; i < n; i++)
	{
		cin >> arr[i]; 
	}

	// call the function here
	


	// output
	// for(auto it : arr)
	// {
	// 	cout << it << " ";
	// }

	for( auto it : unionOfarrays(arr,arr2))
    

    return 0;
}