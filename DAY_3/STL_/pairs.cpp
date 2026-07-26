#include <iostream>
using namespace std;
 
int main()
{

    pair<int , int> p = {2,3};
    pair<string,string> name = {"naman", "thakur"};

    //nested pairs
    pair<int , pair<int, int>> num = {1,{7,8}};

    //pair array
    pair<int,int> arr[] = {{1,2},{3,4},{5,6}};

    cout << p.second << '\n'; 
    cout << name.first << " " << name.second << '\n';

    cout << num.first << " " << num.second.first << " " << num.second.second << '\n';

    cout << arr[1].first;
    return 0;
}