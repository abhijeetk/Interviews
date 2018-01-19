#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

int findMiddleElement(Node* head) {
    // Empty link list
    if (!head)
        return - 1;

    Node* slow_ptr = head;
    Node* fast_ptr = head;
    while (slow_ptr != nullptr && (fast_ptr->next && fast_ptr->next->next != nullptr)) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    return slow_ptr->data;
}

int main() {
    Node* head = new Node(1);
    cout << findMiddleElement(head) << endl;
    head->next = new Node(2);
    cout << findMiddleElement(head) << endl;
    head->next->next = new Node(3);
    cout << findMiddleElement(head) << endl;
    head->next->next->next = new Node(4);
    cout << findMiddleElement(head) << endl;
    head->next->next->next->next = new Node(5);
    cout << findMiddleElement(head) << endl;
    return 0;
}
