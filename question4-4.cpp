#include <iostream>
using namespace std;

struct String {
    char* location;
};

String* newString() {
    String* str = new String;
    str->location = new char[1];
    str->location[0] = '\0'; 
    return str;
}

void append(String* str, char data) {
    int old_size = str->location[0];
    char* new_location = new char[old_size + 2]; 
    for (int i = 0; i < old_size; i++) {
        new_location[i] = str->location[i];
    }
    new_location[old_size] = data;
    new_location[old_size + 1] = '\0'; 
    delete[] str->location;
    str->location = new_location;
}

char characterAt(String* str, int index) {
    return str->location[index + 1]; 
}

void concatenate(String* str1, String* str2) {
    int old_size1 = str1->location[0];
    int old_size2 = str2->location[0];
    int new_size = old_size1 + old_size2;
    char* new_location = new char[new_size + 1]; 
    for (int i = 0; i < old_size1; i++) {
        new_location[i] = str1->location[i];
    }
    for (int i = 0; i < old_size2; i++) {
        new_location[old_size1 + i] = str2->location[i + 1]; 
    }
    new_location[new_size] = '\0'; 
    delete[] str1->location;
    str1->location = new_location;
}

void printString(String* str) {
    int size = str->location[0];
    for (int i = 0; i < size; i++) {
        cout << str->location[i + 1]; 
    }
}

int main() {
    String* str1 = newString();
    String* str2 = newString();

    append(str1, 'C');
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

    printString(str1);
    cout << endl;

    delete[] str1->location;
    delete str1;
    delete[] str2->location;
    delete str2;

    return 0;
}
