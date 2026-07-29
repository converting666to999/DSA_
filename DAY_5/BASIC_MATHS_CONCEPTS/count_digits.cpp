#include <bits/stdc++.h>
using namespace std;

void count_Digits(int n)
{
    // int count = 0; 
    // while(n > 0)
    // {
    //     count++;
    //     n = n / 10;
    // }
    // cout << count;

    int count = (int)log10(n) + 1;
    cout << count;
}

int main()
{

    int n; 
    cin >> n;

    count_Digits(n);
    
    cout << '\n';
    return 0;
}