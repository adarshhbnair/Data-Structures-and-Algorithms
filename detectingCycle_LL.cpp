#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *next;
    Node(int x): val(x),next(nullptr){}
};

bool hasCycle(Node *head){
    if(head == nullptr) return false;

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

int main(){
    Node *head = new Node(3);
    head->next = new Node (2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);
    head->next->next->next->next = head->next;

    if(hasCycle(head)){
        cout<<"Cycle Detected!"<<endl;
    }
    else{
        cout<<"No Cycle Detected!"<<endl;
    }
    return 0;
}