
#include <iostream>
#include <string>

using namespace std;

struct StudentRecord {
    int studentNumber;
    string name;
};

void removeRecord(StudentRecord* collection, int& numRecords, int studentNumber) {
    for (int i = 0; i < numRecords; ++i) {
        if (collection[i].studentNumber == studentNumber) {
            for (int j = i; j < numRecords - 1; ++j) {
                collection[j] = collection[j + 1];
            }
            numRecords--; 
            return; 
        }
    }
}

int main() {
    const int MAX_RECORDS = 100;
    StudentRecord studentCollection[MAX_RECORDS];
    int numRecords = 4;

    studentCollection[0] = {110, "Jessica"};
    studentCollection[1] = {111, "Patrick"};
    studentCollection[2] = {112, "Frank"};
    studentCollection[3] = {113, "Jose"};

    cout << "Removing record with number 111..." << endl;
    removeRecord(studentCollection, numRecords, 1002);
    cout << endl;

    return 0;
}