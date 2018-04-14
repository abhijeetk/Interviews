/*
    Node * alternateReverse( Node* head1, Node*head2){
    // code goes here
    }
    Where ‘Node’ is the structure of a linked list node defined as:

    struct Node{
    int data;
    struct Node *next;
    };
    alternateReverse() must remove the even number nodes from the linked list and append them to the end in reverse order. No extra space was allowed. It was for 5 marks.
    Example:

    Input-1->2->3->4->5->6
    Output-1->3->5->6->4->2

    Input-1->2->3->4->5->6->7->8->9
    Output-1->3->5->7->9->8->6->4->2
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int data)  : data(data), next(nullptr){
    }
};

void alternateReverse(Node *head1, Node *head2) {

}

void alternateReverseUtil(Node *head) {
    if (!head || !head->next) {
        return;
    }

    Node *head1 = head;
    Node *head2 = head->next;
    Node *backup = head2;
    while (head1 && head2) {
        bool even = !head2->next;
        if (even)
            break;

        head1->next = head2->next;
        head1 = head1->next;

        bool odd = !head1->next;
        if (odd) {
            head2->next = nullptr;
            break;
        }

        head2->next = head1->next;
        head2 = head2->next;
    }

    head1->next = backup;
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    //head->next->next->next->next->next = new Node(6);

    alternateReverseUtil(head);
    while (head) {
        cout << head->data << endl;
        head = head->next;
    }
}

