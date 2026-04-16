#include <iostream>
#include <vector>
#include <unordered_set>
#include <random>
#include <list>

class Randomized_Set{
    private:

        std::unordered_set<int> RandSet;
        int val;

        //I will maintain this vector alongside the Set to access the Random Values we need Quickly. Since Unordered_set cannot be accessed with random Library.
        int numBuckets;
        std::vector<std::list<int>> buckets;
        int hash(int key){
            return key % numBuckets;
        }
            
    public:

        Randomized_Set(){
            numBuckets = 1007;
            buckets = std::vector<std::list<int>>(numBuckets);
        }

        bool insert(int val){
            if(RandSet.count(val)>0){
                return false;//Since The Number Already Exists in the Set.
            }
            else{
                RandSet.insert(val);
                int index = hash(val);

                buckets[index].push_back(val);
            }
            return true;//Succesfully Added the Number in the Set.
        }

        bool remove(int val){
            if(RandSet.count(val)>0){
                RandSet.erase(val);
                int index = hash(val);
                buckets[index].remove(val);
                return true;//It Means that the Number Does Exist and We have Succesfully removed it.
            }
            else{
                return false;//It means that the Number Does not Exist at all so we Returned False.   
            }
        }

        int getRandom() {
            // 1. Find out exactly how many unique numbers we currently have.
            // RandSet keeps track of this perfectly!
            int total_items = RandSet.size();

            // 2. Setup the random generator (Your existing code was perfect here)
            std::random_device rd;
            std::mt19937 gen(rd());
    
            // Pick a random 'step' between 0 and (total_items - 1)
            std::uniform_int_distribution<> distr(0, total_items - 1);
            int target_step = distr(gen);

            // 3. Walk through your custom buckets to find the item at that step
            int current_step = 0;
    
            for (int i = 0; i < numBuckets; i++) {
                // Iterate through the linked list at this bucket
                for (int value : buckets[i]) {
                    // If our current step matches the random target, we found our random number!
                    if (current_step == target_step) {
                        return value;
                    }
                    current_step++;
                }
            }
    
            return 0; // Fallback (should never be reached if total_items > 0)
        }
};

int main(){
    Randomized_Set randomSet;
    randomSet.insert(3);
    randomSet.insert(12);
    randomSet.insert(19);
    int rand = randomSet.getRandom();
    
    std::cout<<"The Random Number is : "<<rand<<"\n";

    return 0;
}

