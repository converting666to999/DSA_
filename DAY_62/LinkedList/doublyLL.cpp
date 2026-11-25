#include<iostream> 
#include <vector>

using namespace std;

class Node{

public:
    int data; 
    Node* next;
    Node* prev;

    // constructors 
    Node(int val , Node* frwd , Node* bckwrd)
    {
        data = val; 
        next = frwd; 
        prev = bckwrd;
    }

    Node(int val)
    {
        data = val; 
        next = nullptr; 
        prev = nullptr;
    }

};

Node* convertingArrToDLL(vector<int> &arr)
{
    Node* head = new Node(arr[0]); 
    Node* prev = head; 

    for(int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i] , nullptr , prev); 
        prev -> next = temp;
        prev = temp;
    }

    return head; 
}

// deleting head of doubly LL
Node* dltHead(Node* &head)
{
    Node* temp = head; 
    head = head -> next; 
    head -> prev = nullptr;
    temp -> next = nullptr;
    free(temp);

    return head;
}

// deleting tail of doubly LL
Node* dlttail(Node* &head)
{

      // edge case 
    if(head -> next == nullptr)
        return nullptr;
    
    Node* temp = head; 

    // traversing to eNode of the doubly LL
    while(temp -> next != nullptr)
        temp = temp -> next;

    Node* newTail = temp -> prev; 
    newTail -> next = nullptr; 
    temp -> prev = nullptr; 
    delete(temp); 

    return head;

}

void print(Node* &head)
{
    Node* temp = head; 

    while(temp)
    {
        printf("%d " , temp -> data);
        temp = temp -> next;
    }

    printf("\n");
}

int main(){

    vector<int> arr = {10 , 2 , 3 , 4 , 5 , 8}; 

    //fn call
    Node* head = convertingArrToDLL(arr); 
    // dltHead(head);
    dlttail(head);


    // prnt
    print(head);


    return 0;
}