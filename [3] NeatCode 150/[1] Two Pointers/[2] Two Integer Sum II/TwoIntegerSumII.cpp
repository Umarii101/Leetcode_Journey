#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
        int currentSum = numbers[left] + numbers[right];

        if (currentSum == target) {
            // +1 because the problem is 1-indexed
            return {left + 1, right + 1};
        } 
        else if (currentSum > target) {
            // The sum is too high, move the right pointer to a smaller value
            right--;
        } 
        else {
            // The sum is too low, move the left pointer to a larger value
            left++;
        }
    }
    return {}; // Return empty if no solution is found
}

int main(){
    std::vector<int> numbers = {1,2,3,4};
    int target = 3;
    //Expected Output = {0,1};(But we must return {1,2} since the problem Assumes the 1 Index Array not 0. The index 0 and 1 add up to Target =  3.
    std::vector<int> Result = twoSum(numbers,target);
    std::cout<<"\nResult = {";
    for(int i =0; i<Result.size();i++){
        std::cout<<Result[i]<<", ";
    }
    std::cout<<"}\n";
    return 0;
}
