#include <iostream>
#include <vector> 

using namespace std;

class Node{

public: 

    int data; 
    Node* prev; 
    Node* next; 

    // constructor

    Node(int val , Node* frwd , Node* bkcwrd)
    {
        data = val; 
        prev = bkcwrd; 
        next = frwd; 
    }

    Node(int val)
    {
        data = val; 
        prev = nullptr;
        next = nullptr;
    }
}; 

// converting arr to DLL

Node* cnvrtArrToDll(vector<int> &arr)
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


Node* dltHead(Node* &head)
{

    // edge cases
    if(head -> next == nullptr)
        return nullptr;

    Node* temp = head; 
    head = head -> next; 
    head -> prev = nullptr;
    temp -> next = nullptr;
    delete(temp);

    return head;
}

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


// deleting Kth element in DLL
Node* dltKele(Node* &head , int k)
{
    Node* temp = head; 
    int cnt = 0; 

    while(temp -> next != nullptr)
    {
        cnt++; 
        if(cnt == k) break; 
        temp = temp -> next;
    }

    Node* back = temp -> prev; 
    Node* front = temp -> next; 

    // dealing with edge cases
    if(back == nullptr && front == nullptr)
        return nullptr;
    if(back == nullptr)
        return head = dltHead(head);
    if(front == nullptr) 
        return head = dlttail(head); 

    // deleting the k element 
    back -> next = front;
    front -> prev = back; 
    temp -> prev = nullptr; 
    temp -> next = nullptr;
    delete(temp);

    return head;
}

// deleting the node
void dltNode(Node* temp)
{
    // edge case 
    // if tries to dlt head move to next node
    if(temp -> prev == nullptr)
        temp = temp -> next;

    Node* back = temp -> prev; 
    Node* front = temp -> next;

    if(front == nullptr)
    {
        back -> next = nullptr; 
        temp -> prev = nullptr;
        delete(temp); 
        return;
    }

    back -> next = front; 
    front -> prev = back; 
    temp -> next = temp -> prev = nullptr; 
    delete(temp); 

}

void print(Node* head)
{
    Node* temp = head; 

    while(temp)
    {
        printf("%d " , temp -> data);
        temp = temp -> next; 
    }

    cout << endl; 
}

int main(){

    vector<int> arr = {1 , 2 , 3 , 4 , 6}; 

    Node* head = cnvrtArrToDll(arr);
    
    // fn call
    // head = dltKele(head, 8);
    dltNode(head);

    // print
    print(head);
    return 0;
}