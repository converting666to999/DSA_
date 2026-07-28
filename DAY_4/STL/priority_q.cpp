#include <bits/stdc++.h>
using namespace std;

int main()
{

    priority_queue<int> q; 

    q.push(5); 
    q.push(2); 
    q.push(8); 
    
    q.pop();

    //Minimum heap
    priority_queue<int, vector<int>, greater<int>> q2;

    q2.push(5); 
    q2.push(2); 
    q2.push(8); 

    cout << q2.top() << "\n";
    
    
    return 0;
}