#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    //Defining the Resultant Array;
    std::vector<int> Disappeared_nums;

    //Implementing Binary Search -> [1] Sorting Array first.
    std::sort(nums.begin(),nums.end());
    
    //[2] Now implementing Binary Search
    for(int i=1;i<=nums.size();i++){
        std::cout<<"i = "<<i<<"\n\n";
        if(!std::binary_search(nums.begin(),nums.end(),i)){
            std::cout<<"Found Disappeared Number --> ["<<i<<"]\n";
            Disappeared_nums.push_back(i);
        }
    }

    return Disappeared_nums;
}

int main(){
    std::vector<int> nums = {1,1};
    std::vector<int> output = findDisappearedNumbers(nums);
    std::cout<<"\n\nOutput Array = [";
    for(int i=0; i<output.size();i++){
        std::cout<<output[i]<<" ,";
    }
    std::cout<<"]\n";
    return 0;
}

//Runtime 1690ms || Beats 5.00% || Memory 53.04MB || Beats 76.59%
