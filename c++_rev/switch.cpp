#include <iostream>
using namespace std;
 
int main()
{
    int day; 
    cout << "Enter day no: "; 
    cin >> day; 

    switch(day)
    {
        case 1: 
            cout << "Its monday"; 
            break;
        case 2: 
            cout << "Its tuesday"; 
            break;
        case 3: 
            cout << "Its wednesday"; 
            break;
        case 4: 
            cout << "Its thursday"; 
            break;
        case 5: 
            cout << "Its friday"; 
            break;
        case 6: 
            cout << "Its saturday"; 
            break;
        case 7: 
            cout << "Its sunday"; 
            break;
        default: 
            cout << "Invalid negaz"; 
    }
 

    return 0;
}