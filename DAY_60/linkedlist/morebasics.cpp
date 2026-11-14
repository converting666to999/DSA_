#include <cstddef>
#include <iostream> 
#include <vector> 
using namespace std;

class Node
{
public: 
    int data; 
    Node* next; 

    Node(int val , Node* addr)
    {
        data = val; 
        next = addr;
    }

    Node(int val)
    {
        data = val; 
        next = nullptr;
    }

    Node()
    {
        data = 0;
        next = nullptr;
    }

};

Node* convertingArrToLL(vector<int> &arr)
{
    Node* head = new Node(arr[0]); 
    Node* mover = head; 

    for(int i = 1; i < arr.size(); i++)
    {   
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }

    return head; 
}

// deleting head 
Node* dltHead(Node* &head)
{   
    // edge case 
    if(head == NULL) return head;

    Node* temp = head; 
    head = head -> next; 
    delete(temp); 

    return head;
}

Node* dlttail(Node* &head)
{
    // edge case
    if(head == NULL || head -> next == NULL) return NULL; 

    Node* temp = head; 

    while(temp -> next -> next !=  nullptr)
    {
        temp = temp -> next;    
    }

    free(temp -> next); 
    temp -> next = nullptr;

    return head;
}



int main()
{

    vector<int> arr = {1 , 2 , 3 , 5}; 
    
    // fn call 
    Node* head = convertingArrToLL(arr);
    // dltHead(head); // deletes head
    Node* newhead = dlttail(head);

    // output
    cout << head -> data << endl; 
    Node* temp = newhead;
    while(temp)
    {
        cout << temp -> data << " "; 
        temp = temp -> next;
    }

    cout << endl;

    return 0;
}