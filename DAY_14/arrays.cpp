#include <bits/stdc++.h>
using namespace std;

// tc O(k x n)
// sc O(1) extra 

void left_rotateArray(vector<int> &nums, int k)
{
	int n = nums.size();
	// so that the time limit don't exceed 
	k = k % n; 

	while(k--)
	{
		int first = nums[0];
		for(int i = 1; i < n; i++)
		{	
			// shift arr elements to left
			nums[i - 1] = nums[i];
		}
		//swaps the last element with first element
		nums[n-1] = first;

	}
}

void left_rotateArrayOp(vector<int> &nums, int k)
{
	int n = nums.size(); 
	k = k % n; 

	reverse(nums.begin(), nums.begin() + k); 
	reverse(nums.begin()+k , nums.end()); 
	reverse(nums.begin(), nums.end());
}

int main()
{

   	int m,k; 
   	cin >> m >> k; 
   	vector<int> nums(m); 
   	int n = nums.size();

   	for(int i = 0; i < n; i++)
   	{
   		cin >> nums[i];
   	}

   	left_rotateArrayOp(nums, k); 

   	for(auto it : nums)
   	{
   		cout << it << " ";
   	}

    return 0;
}