#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int> nums, int target){
    std::vector<int> result;   
    int size = nums.size()-1;
    for(int num : nums){
        //Starting from the first number until the last in the vector.
        for(int i = 1; i < size; i++){
            if (num+nums[i] == target){
                //Found our Desired Inputs
                result.push_back(i-1);
                result.push_back(i);
                return result;
            }
        }   
    }
    return result;
}

int main(){
    std::vector<int> nums = {2,7,11,15};
    int Target = 9;
    std::vector<int> Result;
    Result = twoSum(nums,Target);
    std::cout<<"Resultant Indexes = [";
    for(int i = 0; i<Result.size();i++){
        std::cout<<Result[i]<<",";
    }
    std::cout<<"]\n";

    return 0;
}
