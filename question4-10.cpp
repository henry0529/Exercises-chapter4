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

Node* addLists(Node* list1, Node* list2) {
    Node* result = nullptr;
    Node* curr = nullptr;
    int carry = 0;

    while (list1 != nullptr || list2 != nullptr || carry > 0) {
        int sum = carry;
        if (list1 != nullptr) {
            sum += list1->data;
            list1 = list1->next;
        }
        if (list2 != nullptr) {
            sum += list2->data;
            list2 = list2->next;
        }
        if (sum >= 10) {
            carry = 1;
            sum -= 10;
        } else {
            carry = 0;
        }
        if (result == nullptr) {
            result = newNode(sum);
            curr = result;
        } else {
            curr->next = newNode(sum);
            curr = curr->next;
        }
    }
    return result;
}

int main() {
    int value1 = 149;
    int value2 = 245;

    Node* list1 = intToList(value1);
    Node* list2 = intToList(value2);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    Node* sumList = addLists(list1, list2);
    cout << "Sum List: ";
    printList(sumList);

    return 0;
}