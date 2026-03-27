#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_set>


std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> result;
    int size1 = nums1.size();
    int size2 = nums2.size();

    // Strategy: Iterate through the smaller array to be efficient
    if (size1 > size2) {
        for (int num : nums2) {
            // Check if already in our result vector
            bool seen = false;
            for (int j = 0; j < result.size(); j++) {
                if (num == result[j]) {
                    seen = true;
                    break;
                }
            }

            // If not seen, look for it in the larger array (nums1)
            if (!seen) {
                for (int i = 0; i < size1; i++) {
                    if (num == nums1[i]) {
                        result.push_back(num);
                        break; // CRITICAL: Stop once found to stay unique
                    }
                }
            }
        }
    } 

    else {
        for (int num : nums1) {
            // Check if already in our result vector
            bool seen = false;
            for (int j = 0; j < result.size(); j++) {
                if (num == result[j]) {
                    seen = true;
                    break;
                }
            }

            // If not seen, look for it in the other array (nums2)
            if (!seen) {
                for (int i = 0; i < size2; i++) {
                    if (num == nums2[i]) {
                        result.push_back(num);
                        break; // CRITICAL: Stop once found to stay unique
                    }
                }
            }
        }
    }

    return result;
}


int main(){
    std::vector<int> nums1 = {1,2,2,1};
    std::vector<int> nums2 = {2,2};
    //Result = {2}. Only Unique intersection elements in the Resultant Array should be returned. The order does not matter.
    std::vector<int> Result = intersection(nums1,nums2);
    std::cout<<"The Total Elements in Result are : ["<<Result.size()<<"]\n";
    std::cout<<"\nResultant Vector = [";
    for(int i =0; i < Result.size();i++){
        std::cout<<Result[i];
    }
    std::cout<<"]\n";
    return 0;
}
