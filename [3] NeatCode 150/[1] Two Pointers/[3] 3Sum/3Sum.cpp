#include <iostream>
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums){
    std::vector<std::vector<int>> Result;
    int left = 0;
    int right = nums.size()-1;//The last Index of the Nums. We will slowly Iterate from right first, and check the third number along with left and right. If it meets the condition then we push the
                              //                                                                                                                                            Triplet into our Vector Result.
    for(int left =0; left<nums.size()-2;left++){
        for(int right = nums.size()-1; right>left+1;right--){
            int currentSum = nums[left] + nums[right] + nums[right-1];
            if(currentSum == 0){
                //We've Found our Triplet lets push this triplet vector into our vector Result.
                Result.push_back({nums[left], nums[right], nums[right-1]});
            }
        }
    }
    return Result;
}

int main(){
    std::vector<int> nums = {-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> Result = threeSum(nums);
    //Expected Output = [[-1,-1,2],[-1,0,1]] //It returns as A vector that contains Vectors containing Triplets that add up to Zero.
    std::cout<<"\nOutput Vector = [";
    for(int i = 0; i < Result.size();i++){
        std::cout<<"{";
        for(int j = 0; j<Result[i].size();j++){
            std::cout<<Result[i][j]<<",";
        }
        std::cout<<"}, ";
    }
    std::cout<<"}\n";
    return 0;
}
