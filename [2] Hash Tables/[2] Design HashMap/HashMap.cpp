#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class MyHashMap{
    private: 
        int numBuckets;
        std::vector<std::list<int> buckets;

        int hash(int key){
            return key % numBuckets;
        }

    public:
        MyHashMap(){
        numBuckets = 1007;
        buckets = std::vector<std::list<int>>(numBuckets);
        }

        void put(int key, int value){    
         int index = hash(key);

        }


};
