#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *next;
    Node(int x):val(x),next(nullptr){}
};

Node *findMiddle(Node *head){
    if(head == nullptr) return nullptr;

    Node *slow = head;
    Node *fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node *middle = findMiddle(head);
    if(middle){
        cout<<"Middle Node Value: "<<middle->val<<endl;
    }
    return 0;
}