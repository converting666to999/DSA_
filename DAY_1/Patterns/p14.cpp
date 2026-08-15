#include <iostream>
using namespace std;

void pattern14(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(char j = 'A'; j <= 'A' + i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
 
int main()
{
    int n; 
    cin >> n; 

    pattern14(n);
    return 0;
}