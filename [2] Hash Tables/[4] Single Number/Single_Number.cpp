#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <list>

int Single_Number(std::vector <int>& nums){
    std::unordered_set<int> hashset;
    int size = nums.size()-1;
    std::vector<int> dups[size];
    for (int key : nums){
        if(hashset.count(key) > 0){
            //Found a Duplicate. Add it to Dup vector.
            dups.pushback(key);
            hashset.remove(key);//Since A number is only Repeated Twice, We dont need to keep it in out Hashset Anymore, Hence Remove it.
        }
        else{
            hashset.insert(key);//We have not seen this key yet so lets add it to the Hashset.
        }
    }
    return *hashset.begin();
}


//My Proposed Logic.
//nums = {2,2,1,3,3}
//  i          Hashset          Dups
//  0          {2}              {}            
//  1          {}Since 2Dup     {2}
//  2          {1}              {2}
//  3          {1,3}            {2}
//  4          {1}              {2,3}

int main(){
    std::vector<int> nums = {2,2,1,3,3}; 
    //Output should be "1", since "1" is a single number but all others are repeated in nums.
    
    return 0;
}

