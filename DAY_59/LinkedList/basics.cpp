#include <iostream> 
#include <vector>
using namespace std;

// def node 
struct Node{

public: 
    int data; 
    Node* next; 

public:
    // constructor
    Node(int val , Node* addr)
    {
        data = val; 
        next = addr;
    }
}; 

int main()
{
    vector<int> arr = {0 , 1 , 2 , 3 ,4};
    Node *x = new Node(arr[0] , nullptr); 

    cout << x-> data << endl;

    return 0;
}