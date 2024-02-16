#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

struct String {
    Node* head;
    int length;
};

Node* newNode(char data, Node* next = nullptr) {
    Node* node = new Node;
    node->data = data;
    node->next = next;
    return node;
}

String* newString() {
    String* str = new String;
    str->head = nullptr;
    str->length = 0;
    return str;
}

void append(String* str, char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (str->head == nullptr) {
        str->head = newNode;
    } else {
        Node* curr = str->head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    str->length++;
}

char characterAt(String* str, int index) {
    if (index < 0 || index >= str->length) {
        throw out_of_range("Not in range");
    }

    Node* curr = str->head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->data;
}

int main() {
    
    String* str = newString();
    append(str, 'C');
    append(str, 'o');
    append(str, 'l');
    append(str, 'o');
    append(str, 'r');

    for (int i = 0; i < str->length; i++) {
        cout << characterAt(str, i);
    }
    cout << endl;

    Node* curr = str->head;
    while (curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    delete str;

    return 0;
}