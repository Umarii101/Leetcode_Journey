#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_set>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2){
    std::vector<int> result;
    int size1 = nums1.size();
    int size2 = nums2.size();

    //Calculating the total iterations we need. In my opinion it will be more efficient to only iterate all the elements of the smaller vector.
    std::vector<int> total_iterations;
    int difference = size1-size2;
    if(difference > 0){
        for(int num : nums2){
            //Before Proceeding, It would be wise to check if The element already exists in the resultant array or not. This shall prevent duplicates in Result and keep it unique.
            bool seen = false;
            for(int j = 0; j <=result.size();j++){
                if(num== nums2[j]){
                    //Already Exists.
                    seen = true;
                    break;
                }
                else{
                    continue;
                }
            }
            for(int i=0; i<size1;i++){
                if(num == nums2[i] && !seen){//Iterate through all the Elements of The other array.
                    //Found the element that is intersecting.
                    result.push_back(num);
                    i++;
                }
                else{
                    //it does not match. Move on:
                    i++;
                }
            }
        }
    }

    else{
        for(int num : nums1){
            bool seen = false;
            for(int j = 0; j <=result.size();j++){
                if(num== nums1[j]){
                    //Already Exists.
                    seen = true;
                    break;
                }
                else{
                    continue;
                }
            }
            for(int i=0; i<size2;i++){
                if(num == nums1[i] && !seen){//Iterate through all the Elements of The other array.
                    //Found the element that is intersecting.
                    result.push_back(num);
                    i++;
                }
                else{
                    //it does not match. Move on:
                    i++;
                }
            }
        }
    }    

    return result;
}

//My Approach:
//  





int main(){
    std::vector<int> nums1 = {1,2,2,1};
    std::vector<int> nums2 = {2,2};
    //Result = {2}. Only Unique intersection elements in the Resultant Array should be returned. The order does not matter.
    std::vector<int> Result = intersection(nums1,nums2);
    std::cout<<"The Total Elements in Result are : ["<<Result.size()<<"]\n";
    std::cout<<"\nResultant Vector = [";
    for(int i =0; i < Result.size()-1;i++){
        std::cout<<Result[i];
    }
    std::cout<<"]\n";
    return 0;
}
