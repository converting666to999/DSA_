#include <iostream>
using namespace std;

void pattern12(int n)
{  
    int space = 2*n - 2; 
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << j;
        }

        for(int j = 1; j <= space; j++)
        {
            cout << " ";
        }

        for(int j = i; j >= 1; j--)
        {
            cout << j;
        }
        space -= 2;
        cout << endl;
    }
}
 
int main()
{
    int n; 
    cin >> n; 

    pattern12(n);
    return 0;
}