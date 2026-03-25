#include <iostream>
#include <vector>

int singleNumber(std::vector<int>& nums){
    int result =0;
    for (int num : nums){
        result ^= num;
    }
    return result;
}



//Proposed Logic
//Step      Operation       Binary Calculation      Current Result (Decimal)
//Start     0               00                      0
//1         0 ^ 2           00 ^ 10 = 10            2
//2         2 ^ 2           10 ^ 10 = 00            0 (The 2s cancelled out!)
//3         0 ^ 1           00 ^ 01 = 01            1
//4         1 ^ 3           01 ^ 11 = 10            2 (Temporary ""messy"" state)"
//5         2 ^ 3           10 ^ 11 = 01            1 (The 3s cancelled out!)



int main(){
    std::vector<int> nums = {2,2,1,3,3};

    int Result = singleNumber(nums);
    std::cout<<"The Single Number is : "<<Result<<"\n";
    return 0;
}
