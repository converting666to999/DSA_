#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void print()
{   
    // base condition
    if(cnt == 4) return;

    cout << cnt << " "; 
    cnt++;
    print();
}

void printName(int i, int n)
{
   
    if(i > n) return; 
    cout << "raj" << endl; 
    printName(i+1,n);

}

// tc = O(n) sp = O(n)
void printNum(int i, int n)
{
    if(i > n) return; 
    cout << i << " ";
    printNum(i+1, n);  
}

void printNum_r(int i, int n)
{
    if(n < i) return; 
    cout << n << " ";
    printNum_r(i, n-1);  
}


// did it with backtracking
void printNum_BT(int i)
{
    if(i < 1) return; 

    printNum_BT(i-1);  
    cout << i << " ";
}

// with backtrack can't use i-1
void printNum_r_BT(int i , int n)
{
    if(i > n) return; 
    printNum_r_BT(i + 1,n); 
    cout << i << " "; 
}

int main()
{

    printNum_r_BT(1,5);

    

    cout << "\n";
    return 0;
}