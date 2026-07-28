#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.second > p2.first) return true; 
    if(p1.second < p2.second) return false; 

    // if they are the same 
    if(p1.first > p2.first) return true;
    return false;
}

void permutation()
{
    string s = "231"; 

    do{
        cout << s << endl;
    }while(next_permutation(s.begin(), s.end()));
}

int main()
{

    int a[] = {3, 1, 7, 4, 6}; 
    int size = sizeof(a) / sizeof(a[0]);
    // pair<int, int> arr[] = { {5,1},{7,2},{8,2}};
    // int size2 = sizeof(arr) / sizeof(arr[0]);

    // sort(a+2 , a+4);
    // sort(arr, arr+size, greater<int>());

    // sort(arr, arr+size , comp);

    // for(int i = 0; i < size; i++)
    // {
    //     cout << a[i] << " ";
    // }

    // for(int i = 0; i < size2; i++)
    // {
    //     cout << arr[i].first << " " << arr[i].second;
    // }

    int max = *max_element(a, a+size); 
    cout << max << '\n'; 


    permutation();

    cout << "\n";
    return 0;
}