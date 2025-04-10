#include <vector>
#include <iostream>
using namespace std;

// Function to create a linked list from a given array
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList(vector<int>& arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

// Example usage
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(arr);
    cout << "Linked list: ";
    printLinkedList(head);
    return 0;
} 