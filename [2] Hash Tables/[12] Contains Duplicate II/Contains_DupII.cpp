#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        // Key: The number (nums[i])
        // Value: The index where we last saw it
        std::unordered_map<int, int> lastSeen;

        for (int i = 0; i < nums.size(); i++) {
            // 1. Check if we have seen this number before
            if (lastSeen.count(nums[i])) {
                // 2. We found a match! Check if it's "Nearby"
                // i is current index, lastSeen[nums[i]] is the previous index
                if (i - lastSeen[nums[i]] <= k) {
                    return true; 
                }
            }

            // 3. Update the map with the current index.
            // If the number was already there, this updates it to the 
            // NEWEST index, which is better for the next comparison!
            lastSeen[nums[i]] = i;
        }

        return false;
    }
int main(){
    std::vector<int> nums = {1,2,3,1,2,3};
    int k = 2;
    bool Result = containsNearbyDuplicate(nums,k);
    if(Result){
        std::cout<<"The Vector Contains a Nearby Duplicate\n";
    }
    else{
        std::cout<<"The Vector does not Contain a Nearby Duplicate\n";
    }
//Example 1: nums = [1, 2, 3, 1], k = 3
//We see a 1 at index 0.We see another 1 at index 3.
//The distance is (3 - 0) = 3.
//Is 3 <= 3 ? Yes. Result: true.


    return 0;
}
