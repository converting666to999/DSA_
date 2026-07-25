#include <iostream>
using namespace std;

void pattern16(int n)
{
    for(int i = 0; i < n; i++)
    {
        char start = 'A' + i;
        for(int j = 0; j <= i; j++)
        {
            cout << start;
        }
        cout << endl;
    }
}
 
int main()
{
    int n; 
    cin >> n;

    pattern16(n);
    return 0;
}