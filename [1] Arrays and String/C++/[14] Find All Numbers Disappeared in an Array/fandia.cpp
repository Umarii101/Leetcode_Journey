#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;

std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    //Find max Range of (1,n);
    int max = *std::max_element(nums.begin(), nums.end());
    std::cout << "Max value: " << max << std::endl;
    return nums;
}

int main(){
    std::vector<int> nums = {4,3,2,7,8,2,3,1};
    //Expected Output = {5,6}, Since they are not in the list of range (1,n).
    std::vector<int> output = findDisappearedNumbers(nums);
    return 0;
}
