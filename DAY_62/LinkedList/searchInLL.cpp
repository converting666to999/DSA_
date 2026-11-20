#include <iostream> 
#include <vector> 

using namespace std;

class Node{

public: 
    int data; 
    Node* next; 

public:
    Node(int val , Node* addr)
    {
        data = val; 
        next = addr;
    }

    Node(int val)
    {
        data = val;
    }

};

bool search(Node* &head , int el)
{
    Node* temp = head; 
    bool fnd = false; 

    while(temp)
        if(temp -> data == el)
            fnd = true;

    return fnd;
}

int main(){


    return 0;
}