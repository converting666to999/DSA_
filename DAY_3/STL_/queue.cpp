#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    queue<int> q; 

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    // q.pop();

    cout << q.back() << "\n";
    cout << q.front() << '\n';

    for(auto it = q.front(); it != q.back() + 1; it++)
    {
        cout << it << " ";
    }
    return 0;
}