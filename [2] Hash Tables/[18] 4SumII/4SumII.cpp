#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4){
    int Result = 0;
    std::set<std::vector<int>> Tuples;
    for(int i = 0; i < nums1.size();i++){
        if(nums1[i]+nums2[i]+nums3[i]+nums4[i] == 0){
            std::vector<int> temp1 = {i,i,i,i};
            if(Tuples.count(temp1)==0){//It Means that this Combination of indexes is not Present currently, So we store it in our hashset as Vector.
                Tuples.insert(temp1);
            }
        }
        for(int j = 0; j<nums2.size();j++){
            if(nums1[i]+nums2[j]+nums3[i]+nums4[i] == 0){
                std::vector<int> temp2 = {i,j,i,i};
                if(Tuples.count(temp2)==0){
                    Tuples.insert(temp2);
                }
            }
            for(int k = 0; k<nums3.size();k++){
                if(nums1[i]+nums2[j]+nums3[k]+nums4[i] == 0){
                    std::vector<int> temp3 = {i,j,k,i};
                    if(Tuples.count(temp3)==0){
                        Tuples.insert(temp3);
                    }
                }
                for(int l = 0; l<nums2.size();l++){
                    if(nums1[i]+nums2[j]+nums3[k]+nums4[l] == 0){
                        std::vector<int> temp4 = {i,j,k,l};
                        if(Tuples.count(temp4)==0){
                            Tuples.insert(temp4);
                        }
                    }
                }
            }
        }
    }
    Result = Tuples.size();
    return Result;
}

int main(){
    std::vector<int> nums1 = {1,2};  std::vector<int> nums2 = {-2,-1};
    std::vector<int> nums3 = {-1,2};     std::vector<int> nums4 = {0,2};
    //Expected Output  = 2;
    //Explanation : The Two Tuples Are Below.
    //1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
    //2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
    int Result = fourSumCount(nums1,nums2,nums3,nums4);
    std::cout<<"\nTotal Tuples = "<<Result<<"\n";
    return 0;
}
