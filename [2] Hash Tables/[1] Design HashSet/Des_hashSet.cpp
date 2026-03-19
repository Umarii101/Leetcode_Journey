#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class MyHashSet {
private:
    // The number of buckets. We choose a prime number to help distribute 
    // the keys more evenly across the buckets and reduce collisions.
    int numBuckets;
    
    // Our main data structure: A vector where each element is a linked list.
    std::vector<std::list<int>> buckets;

    // A simple private helper function to compute the hash (the bucket index)
    int hash(int key) {
        return key % numBuckets;
    }

public:
    MyHashSet() {
        // 10007 is a prime number. Since there are at most 10^4 (10,000) calls,
        // having ~10,000 buckets means each bucket will likely have 0 or 1 item.
        numBuckets = 10007; 
        
        // Resize the vector to hold our buckets
        buckets = std::vector<std::list<int>>(numBuckets);
    }
    
    void add(int key) {
        int index = hash(key); // Find out which bucket this key belongs to
        
        // Search the linked list in this bucket. 
        // We only add it if it doesn't already exist (Sets don't have duplicates).
        auto it = std::find(buckets[index].begin(), buckets[index].end(), key);
        
        // If the iterator reaches the end, the key wasn't found. We can add it.
        if (it == buckets[index].end()) {
            buckets[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index = hash(key); // Find the bucket
        
        // std::list has a built-in remove function that easily removes 
        // the specific value from the linked list if it exists.
        buckets[index].remove(key);
    }
    
    bool contains(int key) {
        int index = hash(key); // Find the bucket
        
        // Search the linked list for the key
        auto it = std::find(buckets[index].begin(), buckets[index].end(), key);
        
        // If the iterator is NOT at the end, it means we found the key!
        return it != buckets[index].end();
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
