#include <iostream>
using namespace std;
 
int main()
{
    int arr [3][3]; 
    int row_size = sizeof(arr) / sizeof(arr[0]);
    int col_size = sizeof(arr[0]) / sizeof(arr[0][0]);

    for(int n = 0; n < row_size; n++)
    {
        for(int m = 0; m < 3; m++)
        {
            cout << "Enter number at " << n << m << " : "; 
            cin >> arr[n][m];
        }
    }


     for(int n = 0; n < col_size; n++)
    {
        for(int m = 0; m < 3; m++)
        {
            cout << arr[n][m] << " ";
        }
        cout << endl; 
    }


     return 0; 
}