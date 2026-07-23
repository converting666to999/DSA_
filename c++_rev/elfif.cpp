#include <iostream>
using namespace std;
 
int main()
{
    int marks; 
    cout << "Enter your marks: "; 
    cin >> marks; 

    if(marks < 25)
    {
        cout << "F" << endl;
    }
    else if(marks >= 25 && marks <= 44)
    {
        cout << "E" << endl;
    }
      else if(marks >= 45 && marks <= 49)
    {
        cout << "D" << endl;
    }
      else if(marks >= 50 && marks <= 59)
    {
        cout << "C" << endl;
    }
      else if(marks >= 60 && marks <= 79)
    {
        cout << "B" << endl;
    }
    else{
        cout << "A" << endl;
    }
    
    return 0; 
}