#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class LinkedListNode {
public :
    int val;
    LinkedListNode* next;

    LinkedListNode(int new_val) {
        this->val = new_val;
        this->next = nullptr;
    }
};

LinkedListNode* sortLinkList(LinkedListNode* head, int k) {
    // empty linked list
    if (!head)
        return nullptr;

    // linked list has only one node
    if (!head->next)
        return head; 

    LinkedListNode* delete_ptr = head;
    LinkedListNode* head_ref = nullptr;
    LinkedListNode* tail_ref = nullptr;

    int count = k;
    vector<int> vec;
    while (head != nullptr) {
        if (count > 0) {
            vec.push_back(head->val);
            count--;
            if (count == 0) {
                std::sort(vec.begin(), vec.end());
                for (int c : vec) {
                    // Emptt linked list
                    if (!head_ref) {
                        head_ref = new LinkedListNode(c);
                        tail_ref = head_ref;
                    }
                    else {
                        if (tail_ref->next == nullptr) {
                            tail_ref->next = new LinkedListNode(c);
                            tail_ref = tail_ref->next;
                        }
                    }
                }

                // reset for next iteration
                count = k;
                vec.clear();
            }
        }
        head = head->next;
    }

    // delete existing linked list
    while (delete_ptr) {
        LinkedListNode* temp = delete_ptr;
        delete_ptr = delete_ptr->next;
        delete temp;
    }

    return head_ref;
}

int main() {
    LinkedListNode* head = new LinkedListNode(8);
    head->next = new LinkedListNode(5);
    head->next->next = new LinkedListNode(9);
    head->next->next->next = new LinkedListNode(3);

    LinkedListNode* output = sortLinkList(head, 2);
    while (output) {
        cout << output->val << "\t";
        output = output->next;
    }
    cout << endl;
    return 0;
}