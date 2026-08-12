#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> UnionOfArray(vector<int> &a, vector<int> &b)
{   
    vector<int> un;
    int i = 0; 
    int j = 0; 
    int n1 = a.size(); 
    int n2 = b.size(); 

    while(i < n1 && j < n2)
    {
        if(a[i] <= b[j])
        {
            if(un.size() == 0 || un.back() != a[i] )
            {
                un.push_back(a[i]);
            }
            i++;
        }
        else
        {   
             if(un.size() == 0 || un.back() != b[j] )
            {
                un.push_back(b[j]);
            }
            j++;

        }
    }

    while(j < n2)
    {
        if(un.size() == 0 || un.back() != b[j] )
            {
                un.push_back(b[j]);
            }
            j++;
    }

    while(i < n1)
    {
            if(un.size() == 0 || un.back() != a[i] )
            {
                un.push_back(a[i]);
            }
            i++;
    }

    return un;
}

// brute approach
void MoveZeroes(vector<int> &arr)
{
    vector<int> temp; 

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] != 0)
        {
            temp.push_back(arr[i]); 
        }
    }

    for(int i = 0; i < arr.size(); i++)
    {
        arr[i] = temp[i];
    }

    for(int i = temp.size() + 1; i < arr.size(); i++)
    {
        arr[i] = 0;
    }
}

void MoveZeroesOP(vector<int> &arr)
{
    int j = -1; // first pointer
    
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == 0)
        {
            j = i; 
            break;
        }
    }

    if(j == -1) return;

    for(int i = j + 1; i < arr.size(); i++)
    {
        if(arr[i] != 0)
        {
            swap(arr[i],arr[j]); 
            j++;
        }
    }
}

void LeftRotateArray(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d % n; 

    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(),arr.end());


}

int SecondLargest(vector<int> &arr)
{
    int Largest = arr[0]; 
    int Second_largest = -1;

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > Largest)
        {
            int temp = Largest; 
            Largest = arr[i]; 
            Second_largest = temp;
        }
    }
    return Second_largest;
}

bool isSorted(vector<int> &arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] <= arr[i+1])
        {
            return true;
        }
        else return false;
    }
    
}

vector<int> removeDupe(vector<int> &arr)
{
    int j = 0; 

    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[j] != arr[i])
        {
            arr[j + 1] = arr[i]; 
            j++;
        }
    }

    return arr;
}

//brute approach 
// tc O(n^2)
int isMissing(vector<int> &arr)
{
    int n = arr.size() + 1;
    

    for(int i = 0; i <= n; i++)
    {   
        bool found = false;
        for(int j = 0; j < n - 1; j++)
        {
            if(arr[j] == i)
            {
                found = true; 
                break;
            }
        }
        if(!found) return i;

    }

    return -1;

}

// better approach using hash array
int isMissing_Better(vector<int> &arr)
{
    int n = arr.size();
    vector<int> hash(n+1,0); 

    for(int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    for(int i = 0; i < n + 1; i++)
    {
        if(hash[i] == 0)
        return i;
    }
    return -1;
}

//Optimal approach
int isMissing_Optimal(vector<int> &arr)
{
    int n = arr.size();

    int s1 = n * (n + 1) / 2; 
    int s2 = 0;

    for(int i = 0; i < n; i++)
    {
        s2 += arr[i]; 
    }

    //missing number
    return s1 - s2;

}

int isMissing_Optimal2(vector<int> &arr)
{
    int n = arr.size(); 
    int xor1 = 0; 
    int xor2 = 0; 

    for(int i = 0; i < n; i++)
    {
        xor2 = xor2 ^ arr[i]; 
        xor1 = xor1 ^ arr[i + 1];
    }

    xor1 = xor1 ^ n; 
    return xor1 ^ xor2;


}

int main()
{

	vector<int> a = {0, 2, 3, 1, 4}; 
    vector<int> b = {1, 2, 3, 6, 7}; 

    cout << isMissing_Optimal2(a);

    // for(auto it : removeDupe(a))
    // {
    //     cout << it << " ";
    // }




    

    return 0;
}