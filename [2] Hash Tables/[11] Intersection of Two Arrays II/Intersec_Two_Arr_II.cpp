#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2){
    std::vector<int> Result;
    int size1 = nums1.size();
    int size2 = nums2.size();

    //For Efficiency Purpose lets Select the smaller Vector to Iterate.
    if (size1 > size2){
        bool seen = false;
        //This means Nums1 is larger.
        for(int i =0; i < nums2.size(); i++){
            for(int j =0; j<nums1.size();j++){
                if(nums2[i] == nums1[j]){
                    //We have Found a match.
                    std::cout<<"We have Found a match\n";
                    Result.push_back(nums2[i]);
                    nums1.erase(nums1.begin() + j);
                    break;
                }
            }
        }
    }
    else{
        bool seen = false;
        for(int i = 0; i<nums1.size();i++){
            for(int j=0; j<nums2.size();j++){
                if(nums1[i] == nums2[j]){
                    //Found a Match.
                    std::cout<<"Found a Match\n";
                    Result.push_back(nums1[i]);
                    nums2.erase(nums2.begin() + j);
                    break;
                }
            }
        }
    }
    return Result;
}
int main(){
    std::vector<int> nums1 ={43,85,49,2,83,2,39,99,15,70,39,27,71,3,88,5,19,5,68,34,7,41,84,2,13,85,12,54,7,9,13,19,92};    
    std::vector<int> nums2 = {10,8,53,63,58,83,26,10,58,3,61,56,55,38,81,29,69,55,86,23,91,44,9,98,41,48,41,16,42,72,6,4,2,81,42,84,4,13};
    //Expected Output = [2,2]; //Only Return the Intersections and however many times they appear.
        //Example
            //Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
            //Output: [4,9]
        //Explanation: [9,4] is also accepted.
    std::vector<int> Result;
    Result = intersect(nums1,nums2);
    std::cout<<"Result = [";
    for(int i =0; i<Result.size();i++){
        std::cout<<Result[i]<<", ";
    }
    std::cout<<"]\n";
    return 0;
}
