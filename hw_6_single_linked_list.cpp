/*
 Part 2: Discussion
 (1) Pseudocode covering all cases:

     // reverseList(head):
     prev <- null
     curr <- head
     while curr != null do
         nextNode <- curr.next       // save next
         curr.next <- prev           // reverse link
         prev <- curr                // advance prev
         curr <- nextNode            // advance curr
     end while
     return prev                   // new head

    This handles:
      - 0 nodes: head is null, loop skipped, returns null
      - 1 node: loop runs once, nextNode is null, reverses to itself, returns node
      - 2 nodes: correctly swaps links
      - ≥3 nodes: iteratively reverses all links

 (2) C++ Implementation based on pseudocode: see reverseList() below.

 (3) Test all cases in main():
     - Empty list (0 nodes)
     - Single node (1 node)
     - Two nodes (2 nodes)
     - Multiple nodes (≥3 nodes)

 (4) Combining cases:
     The iterative pointer-reversal algorithm unifies all scenarios. No separate branches are needed: initial prev=null handles empty and one-node lists seamlessly.

 (5) Final work: complete reverseList function:
     ListNode* reverseList(ListNode* head) {
         ListNode* prev = nullptr;
         ListNode* curr = head;
         while (curr) {
             ListNode* nextNode = curr->next;
             curr->next = prev;
             prev = curr;
             curr = nextNode;
         }
         return prev;
     }
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

// Function to reverse the linked list.
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Helper to print a list
void printList(ListNode* head) {
    ListNode* p = head;
    if (!p) {
        cout << "@" << endl;
        return;
    }
    while (p) {
        cout << p->val;
        if (p->next) cout << " -> ";
        else cout << " -> @";
        p = p->next;
    }
    cout << endl;
}

// Helper to build a list from initializer list
ListNode* buildList(initializer_list<int> vals) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int v : vals) {
        ListNode* node = new ListNode(v);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

int main() {
    // Case 1: empty list
    ListNode* head0 = nullptr;
    cout << "Original (0 nodes): "; printList(head0);
    head0 = reverseList(head0);
    cout << "Reversed (0 nodes): "; printList(head0);
    cout << endl;

    // Case 2: single node
    ListNode* head1 = buildList({1});
    cout << "Original (1 node): "; printList(head1);
    head1 = reverseList(head1);
    cout << "Reversed (1 node): "; printList(head1);
    cout << endl;

    // Case 3: two nodes
    ListNode* head2 = buildList({1, 2});
    cout << "Original (2 nodes): "; printList(head2);
    head2 = reverseList(head2);
    cout << "Reversed (2 nodes): "; printList(head2);
    cout << endl;

    // Case 4: multiple nodes
    ListNode* head3 = buildList({1, 2, 3, 4, 5, 6});
    cout << "Original (≥3 nodes): "; printList(head3);
    head3 = reverseList(head3);
    cout << "Reversed (≥3 nodes): "; printList(head3);
    cout << endl;

    return 0;
}
