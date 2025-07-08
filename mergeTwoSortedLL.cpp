#include <iostream> // For input/output operations
#include <vector>   // Not strictly needed for the efficient approach, but kept for general utility
#include <algorithm> // Not strictly needed for the efficient approach, but kept for general utility

// Define a Node structure for the linked list
class Node {
public:
    int data;
    Node *next;

    // Constructor to initialize a new node
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node *sortedMerge(Node *head1, Node *head2) {
    Node *dummy = new Node(-1);
    Node *current = dummy; 

    // Iterate while both lists have nodes
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            current->next = head1; 
            head1 = head1->next;  
        } else {
            current->next = head2;
            head2 = head2->next; 
        }
        current = current->next; 
    }

    // If one list is exhausted, append the remaining nodes of the other list
    if (head1 != nullptr) {
        current->next = head1;
    } else if (head2 != nullptr) {
        current->next = head2;
    }

    // The merged list starts from dummy->next (as dummy itself is just a placeholder)
    return dummy->next;
}

// Function to print the linked list
void printList(Node *curr) {
    while (curr != nullptr) {
        std::cout << curr->data;
        if (curr->next != nullptr)
            std::cout << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

// Main function to test the sortedMerge function
int main() {
    // First linked list: 5 -> 10 -> 15
    Node *head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);

    // Second linked list: 2 -> 3 -> 20
    Node *head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);

    std::cout << "First List: ";
    printList(head1);
    std::cout << "Second List: ";
    printList(head2);

    // Merging the two sorted linked lists
    Node *res = sortedMerge(head1, head2);

    std::cout << "Merged List: ";
    printList(res);

    // It's good practice to free allocated memory in C++
    // (though for small examples like this, it might not be critical)
    // For a complete solution, you'd iterate through res and delete nodes.
    // Example:
    Node* temp;
    while(res != nullptr) {
        temp = res;
        res = res->next;
        delete temp;
    }

    return 0;
}