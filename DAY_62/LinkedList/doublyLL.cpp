#include<iostream> 
#include <vector>

using namespace std;

typedef struct Node{

public:
    int data; 
    Node* next;
    Node* prev;

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

} nd;

nd* convertingArrToDLL(vector<int> &arr)
{
    nd* head = new nd(arr[0]); 
    nd* prev = head; 

    for(int i = 1; i < arr.size(); i++)
    {
        nd* temp = new nd(arr[i] , nullptr , prev); 
        prev -> next = temp;
        prev = temp;
    }

    return head; 
}

// deleting head of doubly LL
nd* dltHead(nd* &head)
{
    nd* temp = head; 
    head = head -> next; 
    head -> prev = nullptr;
    temp -> next = nullptr;
    free(temp);

    return head;
}

// deleting tail of doubly LL
Node* dlttail(Node* &head)
{
    Node* temp = head; 

    // traversing to end of the doubly LL
    while(temp -> next != nullptr)
        temp = temp -> next;

    Node* nxt = temp; 
    temp = temp -> prev; 
    temp -> next = nullptr; 
    nxt -> prev = nullptr;
    free(nxt); 

    return head;

}

void print(nd* &head)
{
    nd* temp = head; 

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
    nd* head = convertingArrToDLL(arr); 
    // dltHead(head);
    dlttail(head);


    // prnt
    print(head);


    return 0;
}