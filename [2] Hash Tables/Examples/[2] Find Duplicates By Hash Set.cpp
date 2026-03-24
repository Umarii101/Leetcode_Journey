#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

// This is the function we analyzed
bool findDuplicates(vector<int>& keys) {
    unordered_set<int> hashset;

    cout << "--- Starting Duplicate Check ---" << endl;

    for (int key : keys) {
        cout << "Checking number: " << key << "... ";
        
        // 1. Check if the guard has seen this number before
        if (hashset.count(key) > 0) {
            cout << "MATCH FOUND! " << key << " is a duplicate." << endl;
            return true;
        }

        // 2. If not found, the guard writes it down (inserts it)
        cout << "First time seeing " << key << ". Adding to set." << endl;
        hashset.insert(key);
    }

    cout << "Finished loop. No duplicates found." << endl;
    return false;
}

int main() {
    // Test Case 1: Contains a duplicate (the number 20)
    vector<int> studentIDs = {10, 20, 30, 40, 20, 50};
    
    cout << "Testing List: {10, 20, 30, 40, 20, 50}" << endl;
    if (findDuplicates(studentIDs)) {
        cout << "Result: This list has duplicates." << endl;
    } else {
        cout << "Result: All IDs are unique." << endl;
    }

    cout << "\n--------------------------------\n" << endl;

    // Test Case 2: All unique
    vector<int> employeeIDs = {101, 102, 103};
    
    cout << "Testing List: {101, 102, 103}" << endl;
    if (findDuplicates(employeeIDs)) {
        cout << "Result: This list has duplicates." << endl;
    } else {
        cout << "Result: All IDs are unique." << endl;
    }

    return 0;
}
