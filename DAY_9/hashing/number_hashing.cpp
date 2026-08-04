#include <bits/stdc++.h>
using namespace std;

int main()
{

    //hash 

    int n;
    cin >> n; 
    int arr[n]; 

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //pre compute hash array
    int hash[13] = {0};
    for(int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    int q; 
    cin >> q; 
    while(q--)
    {
        int number; 
        cin >> number; 

        // fetch
        cout << number << " = " << hash[number] << " times";
    }

    return 0;
}