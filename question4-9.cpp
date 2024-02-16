#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int data, Node* next = nullptr) {
    Node* node = new Node;
    node->data = data;
    node->next = next;
    return node;
}

Node* intToList(int value) {
    if (value < 0) {
        throw invalid_argument("Must be a positive integer");
    }

    Node* head = nullptr;
    Node* curr = nullptr;
    while (value > 0) {
        int digit = value % 10;
        value /= 10;

        if (head == nullptr) {
            head = newNode(digit);
            curr = head;
        } else {
            curr->next = newNode(digit);
            curr = curr->next;
        }
    }
    return head;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int value = 149;
    Node* list = intToList(value);

    printList(list);

    Node* curr = list;
    while (curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    return 0;
}