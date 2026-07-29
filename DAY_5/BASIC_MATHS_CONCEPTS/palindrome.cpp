#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n)
{   
    int original = n;
    int r_n = 0;
    while(n > 0)
    {
        int ls_digit = n % 10;
        r_n = (r_n * 10) + ls_digit;
        n = n / 10; 
    }

    if(r_n == original) return true; 
    return false;
}

int main()
{
    int n; 
    cin >> n;

    cout << isPalindrome(n);
    
    cout << '\n';
    return 0;
}