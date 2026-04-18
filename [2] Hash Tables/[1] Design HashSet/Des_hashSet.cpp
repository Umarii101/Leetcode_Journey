#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class MyHashSet {
private:
    int numBuckets;

    std::vector<std::list<int>> buckets;

    int hash(int key){
        return key % numBuckets;
    }

public:
    MyHashSet(){

        numBuckets = 1007;
        buckets = std::vector<std::list<int>>(numBuckets);
        
    }

    void add (int key){
        int index = hash(key);
        // Search linked list to find if the key already exists in our list or not.
        auto it = std::find(buckets[index].begin(), buckets[index].end(), key);
        //std::cout<<"[Iterator Speaking] I am Equal to ["<<it<<"]\n";
        //If the iterator reaches the endm the key was not found, We can add it:
        if (it == buckets[index].end()){
            buckets[index].push_back(key);
        }
    }

    bool contains(int key){
        int index = hash(key);
        auto it = std::find(buckets[index].begin(), buckets[index].end(), key);
        
        // If the iterator has reached the end and we have not found the key, it means we can add our key to the list:
        return it != buckets[index].end();
    }

    void remove(int key){
        int index = hash(key);

        buckets[index].remove(key);
    }

};

int main() {
    // 1. Initialize the HashSet
    MyHashSet myHashSet;
    std::cout << "HashSet initialized.\n\n";

    // 2. Add 1 and 2
    myHashSet.add(1);
    std::cout << "Added: 1" << std::endl;
    myHashSet.add(2);
    std::cout << "Added: 2" << std::endl;

    // 3. Check for 1 (Should be True)
    std::cout << "Contains 1? " 
              << (myHashSet.contains(1) ? "True" : "False") << std::endl;

    // 4. Check for 3 (Should be False, not added yet)
    std::cout << "Contains 3? " 
              << (myHashSet.contains(3) ? "True" : "False") << std::endl;

    // 5. Add 2 again (Testing duplicate handling - it shouldn't add a second '2')
    myHashSet.add(2);
    std::cout << "\nAttempted to add 2 again." << std::endl;

    // 6. Check for 2 (Should be True)
    std::cout << "Contains 2? " 
              << (myHashSet.contains(2) ? "True" : "False") << std::endl;

    // 7. Remove 2
    myHashSet.remove(2);
    std::cout << "\nRemoved: 2" << std::endl;

    // 8. Check for 2 again (Should be False now)
    std::cout << "Contains 2 after removal? " 
              << (myHashSet.contains(2) ? "True" : "False") << std::endl;

    return 0;
}
