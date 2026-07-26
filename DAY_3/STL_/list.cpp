#include <bits/stdc++.h>
using namespace std;
 
int main()
{   
    // similar to vector but gives front operation
    list<int> l;

    l.push_back(20);
    l.emplace_back(30); 
    l.emplace_back(40); 
    l.emplace_back(50); 

    // l.push_front(10);
    l.emplace_front(10);
    l.pop_back();

    for(auto it : l)
    {
        cout << it << " ";
    }
    return 0;
}