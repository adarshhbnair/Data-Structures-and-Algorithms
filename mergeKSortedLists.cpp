#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Comparator for the priority queue
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min-heap based on node value
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Create a min-heap
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        // Insert the head of each list into the min-heap
        for (ListNode* list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }

        // Dummy node to help with the merged list
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // While there are nodes in the min-heap
        while (!minHeap.empty()) {
            // Get the smallest node
            ListNode* smallestNode = minHeap.top();
            minHeap.pop();

            // Add it to the merged list
            tail->next = smallestNode;
            tail = tail->next;

            // If there is a next node, add it to the min-heap
            if (smallestNode->next) {
                minHeap.push(smallestNode->next);
            }
        }

        // Return the merged list, which starts from the next of the dummy node
        return dummy.next;
    }
};

// Example usage
int main() {
    // Create some test linked lists
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    vector<ListNode*> lists = {list1, list2, list3};

    Solution solution;
    ListNode* mergedList = solution.mergeKLists(lists);

    // Print the merged list
    while (mergedList) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }

    return 0;
}
