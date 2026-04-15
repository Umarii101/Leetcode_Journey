#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::vector<int> topKFrequent(std::vector<int>& nums, int k){
    std::vector<int> Result;
    std::unordered_map<int,int> freq;
    std::unordered_set<int> filter;
    for(int num : nums){
        if(freq[num].count()>0){
            freq[num]++;//Update the count for that number if it already exists in the map. (meaning everytime a number is repeated, it's index is incremented.
        }
        else{
            freq.insert(num);
        }
    }
    for(int j =0; j<k;j++){
        int temp = 0;
        for(int i=0; i<nums.size();i++){
            filter.insert(freq[nums[i]]);
            if(i==0){
                continue;
            }
            if(i>0){
                if(filter[nums[i]]>filter[nums[i-1]]){
                    filter.erase(nums[i-1]);
                    temp = nums[i];
                    freq.erase(nums[i]);//Delete The Biggest k we found so the next K-Loop will not have this big value and will find the next big K.
                }
                else{
                    filter.erase(nums[i]);
                    temp = nums[i-1];
                    freq.erase(nums[i-1]);//Delete The Biggest k we found so the next K-Loop will not have this big value and will find the next big K.
                }
            }
        }//At the end of this loop we shall have the Biggest of the K. Now we need k-1 More Entries in the Result Vector.
         Result.push_back(temp);    //Now we need to store Top K in the Result Vector.
    }
    return Result;
}

int main(){
//Example 3:
    std::vector<int> nums = {1,2,1,2,1,2,3,1,3,2};
    int k = 2;
    std::vector<int> Result = topKFrequent(nums,k);
    std::cout<<"Result = {";
    for(int i=0;i<Result.size();i++){
        std::cout<<Result[i]<<",";
    }
    std::cout<<"}\n";
//Output: [1,2] Since k=2. So Top K frequncy numbers are 1 and 2.

    return 0;
}
