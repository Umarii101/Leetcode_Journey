#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;

std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    //Find max Range of (1,n);
    int max = *std::max_element(nums.begin(), nums.end());
    std::cout << "Max value: " << max << std::endl;
    //We've Found the maximun Value in the array, Now we need to compare only with O(n) loop.
    std::vector<int> Disappeared_nums;
    int j=0;
    
    //Outer Loop to track all the elements of the nums Array.
    for(int k=0; k<nums.size();k++){
        //Inner Loop to compare a single index of Array with (1,max).
        for(int i=1; i<=max;i++){
            if(nums[k]==i){
                std::cout<<"Value "<<i<<" Exists. Proceed \n";
            }
            else{
                //Creating the Resultant Array with total j indexes.
                std::cout<<"Found Missing Number "<<i<<"\n";
                Disappeared_nums.push_back(i);
                j++;
            }
        }
    }

    return Disappeared_nums;
}

int main(){
    std::vector<int> nums = {4,3,2,7,8,2,3,1};
    //Expected Output = {5,6}, Since they are not in the list of range (1,n).
    std::vector<int> output = findDisappearedNumbers(nums);
    std::cout<<"\n\nOutput Array = [";
    for(int i=0; i<output.size();i++){
        std::cout<<output[i]<<" ,";
    }
    std::cout<<"]\n";
    return 0;
}
