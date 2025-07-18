#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    int carry = 0;

    while(l1 != nullptr || l2 != nullptr || carry>0){
        int sum = carry;

        if(l1 != nullptr){
            sum +=l1->val;
            l1 = l1->next;
        }
        if(l1 != nullptr){
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum/10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }

    if(carry>0){
        curr->next = new ListNode(carry);
    }
    return dummy->next;
}

void printList(ListNode *head){
    while(head != nullptr){
        cout<<head->val;
        if(head->next != nullptr){
            cout<<" ->";
        }
        head = head->next;
    }
    cout<<endl;
}

int main(){
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *result = addTwoNumbers(l1,l2);
    printList(result);
    return 0;
}