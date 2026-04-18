#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4){
    int Result = 0;
    std::unordered_map<int,int> Sum_freq;
    for(int i = 0; i < nums1.size();i++){
        for(int j = 0; j<nums2.size();j++){
           int sum1= nums1[i]+nums2[j];
           Sum_freq[sum1]++;
        }
    }

    for(int k = 0; k<nums3.size();k++){
        for(int l = 0; l<nums4.size();l++){
            int sum2 = nums3[k]+nums4[l];
            int target = -sum2; //Since The -sum2 is what actually returns back the Total Sum of Both groups == 0.
                                
            if(Sum_freq.count(target)){
                Result += Sum_freq[target];
            }
        }
    }

    return Result;
}

int main(){
    std::vector<int> nums1 = {1,2};  std::vector<int> nums2 = {-2,-1};
    std::vector<int> nums3 = {-1,2};     std::vector<int> nums4 = {0,2};
    //Expected Output  = 2;
    //Explanation : The Two Sum_freq Are Below.
    //1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
    //2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
    int Result = fourSumCount(nums1,nums2,nums3,nums4);
    std::cout<<"\nTotal Sum_freq = "<<Result<<"\n";
    return 0;
}
