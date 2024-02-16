#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void replaceString(char* source, const char* target, const char* replaceText) {
    int sourceLength = strlen(source);
    int targetLength = strlen(target);
    int replaceTextLength = strlen(replaceText);
    
    char* newString = new char[sourceLength + 1]; 
    
    strcpy(newString, source);
    
    char* currentPosition = strstr(newString, target);
    while (currentPosition != nullptr) {
        int distance = currentPosition - newString;
        
        strcpy(newString + distance, replaceText);
        
        currentPosition = strstr(currentPosition + replaceTextLength, target);
    }
    strcpy(source, newString);
}

int main() {
   
    const char* source = "abcdabee";
    const char* target = "ab";
    const char* replaceText = "xyz";
    
    char* newString = new char[strlen(source) + 1]; 
    strcpy(newString, source);
    replaceString(newString, target, replaceText);
    cout << "New string: " << newString << endl;
    
    delete[] newString;
    
    return 0;
}
