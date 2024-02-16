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
        throw out_of_range("Index out of range");
    }

    Node* curr = str->head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->data;
}

void concatenate(String* str1, String* str2) {
    Node* curr = str2->head;
    while (curr != nullptr) {
        append(str1, curr->data);
        curr = curr->next;
    }
}

int main() {

    String* str1 = newString();
    String* str2 = newString();

    append(str1, 'c');
    append(str1, 'o');
    append(str1, 'l');
    append(str1, 'o');
    append(str1, 'r');

    append(str2, 'G');
    append(str2, 'r');
    append(str2, 'e');
    append(str2, 'e');
    append(str2, 'n');

    concatenate(str1, str2);

    for (int i = 0; i < str1->length; i++) {
        cout << characterAt(str1, i);
        }
            cout << endl;

    Node* curr = str1->head;
    while (curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
         }
         delete str1;

    curr = str2->head;
    while (curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
        }
            delete str2;

    return 0;
}
