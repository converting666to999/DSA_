#include <iostream>
using namespace std;

void PrintName(string name)
{
    cout << "hey " << name;
 
}
 
int add(int num1, int num2)
{
    return num1 + num2;
}

int max(int n1, int n2)
{
    if(n1 > n2)
    {
        return n1;
    }
    else{
        return n2;
    }
}

int main()
{
    int num1 , num2; 
    cout << "Enter two numbers: "; 
    cin >> num1 >> num2; 

    cout << max(num1, num2);
    return 0;
}