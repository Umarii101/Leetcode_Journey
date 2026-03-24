#include <iostream>
#include <unordered_set>
#include <vector>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> hashset; //I will use this Hashset to keep track of seen integers in nums.
    for (int key : nums){
        if(hashset.count(key) > 0){
            std::cout<<"The Key ["<<key<<"] Already exists in the list\n";
            return true; //Since we found a Duplicate, Return the function.
        }
        //Otherwise Add the Key to hashset if it is not a Duplicate.
        hashset.insert(key);
    }
    hashset.clear();//Free up memory.
    return false; //Since we have Went through all of the List and have not Found a single Duplicate, The function returns False.
    
}

int main(){
    std::vector <int> nums = {1,2,3,1,2,3,1,4,5,6,8};
    bool Result;
    Result = containsDuplicate(nums);
    if (Result){
        std::cout<<"\n[Result] -> The List has Duplicates in it.\n";
    }
    else{
        std::cout<<"\n[Result] -> The List Does not have Any Duplicates in it.\n";
    }

}
