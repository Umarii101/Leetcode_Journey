#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class MyHashMap{
    private: 
        int numBuckets;
        std::vector<std::list<std::pair<int,int>>> buckets;

        int hash(int key){
            return key % numBuckets;
        }

    public:

        MyHashMap(){
        numBuckets = 1007;
        buckets.resize(numBuckets);
        }

        void put(int key, int value){    
            int index = hash(key);
            // Look through the list at this bucket
            for (auto &pair : buckets[index]) { //The '&' Ensures that when we find the key, the update happens in the Actual HashMap instead of a copy.
                if (pair.first == key) {
                    // Key exists! Update the value and exit
                    pair.second = value;
                    return;
                }
            }

        // Key doesn't exist, so add a new pair to the list
        buckets[index].push_back({key, value});        
        }
        
        int get(key){
            int index = hash(key);
            for(auto &pair : buckets[index]){
                if(pair.first == key){
                    return pair.second; //The key exists and we return it.
                }    
            }
            return -1; //The Key does not exist in this our Hashmap.
    
        void remove(int key){
            int index = hash(key);
            //Looking through the list in our bucket.
            //For Best C++ Practice, we create a nickname for the specific bucket we are interested in.
            auto &currentBucket = buckets[index];

            for(auto it = currentBucket.begin(); it != currentBucket.end(); ++it){
                if(it->first == key){
                    //Snip this link out of the chain.
                    currentBucket.erase(it);
                    return;     //We have successfully removed the desired key and it's value. We are Done.
            }
        }


};
