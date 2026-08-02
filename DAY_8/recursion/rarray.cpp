#include <bits/stdc++.h>
using namespace std;

// with only one variable
void rev(int i , int n, int arr[])
{
    if(i > n/2) return;
    swap(arr[i],arr[n-i-1]);
    rev(i+1,n,arr);

}

bool isPalindrome(int i, string &str)
{
    if(i >= str.size()) return true;
    if(str[i] != str[str.size()-i-1]) return false; 

    return isPalindrome(i+1,str);
}

int main()
{

    // int n;
    // cin >> n; 
    // int arr[n];

    // for(int i = 0; i < n; i++) cin >> arr[i];

    // rev(0,n,arr);

    // for(int i = 0; i < n; i++)
    // {   
    //     cout << arr[i] << " ";
    // }

    string name; 
    cin >> name; 

    cout << isPalindrome(0,name);

    cout << '\n';
    return 0;
}