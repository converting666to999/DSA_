#include <bits/stdc++.h>
using namespace std;

bool isArmstrong(int n)
{
    int dupe = n;
    int sum = 0; 
    while(n > 0)
    {
        int ls_digit = n % 10; 
        sum = sum + pow(ls_digit,3);
        n = n/10; 
    }

    if(dupe == sum) return true; 
    else return false;

}

int main()
{
    int n; 
    cin >> n;
    
    cout << isArmstrong(n); 

    return 0;
}