#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& numbers, int target){
    std::vector<int> Result;
    for(int i = 0; i<numbers.size();i++){
        for(int j = i+1; j<numbers.size();j++){
            if(numbers[i]+numbers[j] == target){
                //We found our pair.Lets save it into our vector.
                Result.push_back(i+1);
                Result.push_back(j+2);
            }
        }
    }
    return Result;
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
