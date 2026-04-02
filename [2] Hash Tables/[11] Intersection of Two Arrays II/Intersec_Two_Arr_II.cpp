#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2){
    std::vector<int> Result;
    std::unordered_set<int> HashSet;

    int size1 = nums1.size();
    int size2 = nums2.size();

    //For Efficiency Purpose lets Select the smaller Vector to Iterate.
    if (size1 > size2){
        bool seen = false;
        //This means Nums1 is larger.
        for(int i =0; i < size2; i++){
            for(int j =0; j<size1;j++){
                if(nums2[i] == nums1[j]){
                    //We have Found a match.
                    std::cout<<"We have Found a match\n";
                    seen = true;
                }
            }
            //No intersection Exists for this Value, Lets remove it from the vector and shift the values to right.
            if(!seen && i != size2-1 ){
                for(int it = i; it < size2; it++){
                    nums2[it] = nums2[it+1];
                }
            }
        }

    return nums2;
    }
    else{
        bool seen = false;
        for(int i = 0; i<size1;i++){
            for(int j=0; j<size2;j++){
                if(nums1[i] == nums2[j]){
                    //Found a Match.
                    std::cout<<"Found a Match\n";
                }
            }
            if(!seen && i!=size1-1){
                for(int it=i;it<size1;it++){
                    nums1[it] = nums1[it+1];
                }
            }
        }
    return nums1;
    } 
}
int main(){
    std::vector<int> nums1 = {4,9,5};
    std::vector<int> nums2 = {9,4,9,8,4};
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
