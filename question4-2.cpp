#include <iostream>
#include <cstring>

using namespace std;

char* substring(const char* arrayString, int startingPos, int length) {
    int originalLength = strlen(arrayString);
    
    if (startingPos < 0 || startingPos >= originalLength || length <= 0 || startingPos + length > originalLength) {
        return nullptr; 
    }
    
    char* newSubstring = new char[length + 1]; 
    
    strncpy(newSubstring, arrayString + startingPos, length);
    
    newSubstring[length] = '\0';
    
    return newSubstring;
}

int main() {
    
    const char* initialString = "abcdefg";
    int startingPos = 3;
    int length = 4;
    
    char* newSubstring = substring(initialString, startingPos, length);
    
    if (newSubstring != nullptr) {
        cout << "New substring: " << newSubstring << endl;
    } else {
        cout << "Invalid parameters!" << endl;
    }
    
    delete[] newSubstring;
    
    return 0;
}