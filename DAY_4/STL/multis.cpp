#include <bits/stdc++.h>
using namespace std;

int main()
{

    multiset<int> s; 

    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(1);

    // s.erase(1);

    // auto it = s.count(1);

    for(auto it : s)
    {
        cout << it << " ";
    }


    cout << '\n';
    return 0;
}