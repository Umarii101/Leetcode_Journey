#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int> nums, int target){
    std::vector<int> result;   
    for(int i = 0; i<= nums.size()-1;i++){
        //Starting from the first number until the last in the vector.
        int num = nums[i];
        for(int j = i+1; j <= nums.size()-1; j++){        
            if (num+nums[j] == target){
                //Found our Desired Inputs
                std::cout<<"The Target has been Found at Index ["<<j-1<<"] & ["<<j<<"].\nTarget = "<<target<<"\n";
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}

int main(){
    std::vector<int> nums = {3,2,4};
    int Target = 6;
    std::vector<int> Result;
    Result = twoSum(nums,Target);
    std::cout<<"Resultant Indexes = [";
    for(int i = 0; i<Result.size();i++){
        std::cout<<Result[i]<<",";
    }
    std::cout<<"]\n";

    return 0;
}
