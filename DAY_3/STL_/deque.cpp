#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    //all functions are similar to vector

    deque<int> d; 

    d.push_back(10);
    d.emplace_back(20);

    d.push_front(30); 
    d.pop_back();

    for(auto it : d)
    {
        cout << it << " ";
    }
    
    return 0;
}